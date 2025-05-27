// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
using System.Text.Json;

namespace UPRISE_PROFILER_APPLICATION
{
    class Globals
    {
        public static Form1 form1 ;
        public static string Logpath;
        public static List<ProfilingTimerEvent> _profilingTimerEvents_Main = new List<ProfilingTimerEvent>();
        public static List<ProfilingTimerEvent> _profilingTimerEvents_Init = new List<ProfilingTimerEvent>();
        public static List<ProfilingTimerEvent> _profilingTimerEvents_Exit = new List<ProfilingTimerEvent>();
        public static Dictionary<ulong, List<ProfilingTimerEvent>> _profilingTimerEvents_Threads = new();
        public static Dictionary<ulong, FunctionStructure> _functionStructure_threads = new();
        public static FunctionStructure _functionStructure_main = new FunctionStructure();
        public static FunctionStructure _functionStructure_init = new FunctionStructure();
        public static FunctionStructure _functionStructure_exit = new FunctionStructure();
    }
    public static class Program
    {
       
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {


            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            //TODO : reimplement path to avoid leaking folder structure
            {
                List<string> events = new List<string>();
                string profilerLog = File.ReadAllText(path + "\\Profiling.txt"); //-V3039
                var a = profilerLog.Split("|%|").ToList();
                List<ProfilingTimerEvent> s = new List<ProfilingTimerEvent>();
                foreach(var sdfnmgrtblueiahwiv in a)
                {
                    if (sdfnmgrtblueiahwiv.Contains("#"))
                    {
                        continue;
                    }
                    s.Add(JsonSerializer.Deserialize<ProfilingTimerEvent>(sdfnmgrtblueiahwiv));
                }
                ulong inmain = 0;
                ulong inexit = 0;
                ulong none = 0;
                ulong inThreads = 0;
                foreach (var jsonString in a)
                {
                    if (jsonString.Contains("#"))
                    {
                        continue;
                    }
                    var profilingEvent = JsonSerializer.Deserialize<ProfilingTimerEvent>(jsonString);
                    if (profilingEvent != null)
                    {
                        if (profilingEvent.Details.Stacktrace.Any(x => x.Symbol.Name == "invoke_main"))
                        {
                            Globals._profilingTimerEvents_Main.Add(profilingEvent);
                            inmain++;
                        }
                        else if (profilingEvent.Details.Stacktrace.Any(x => x.Symbol.Name == "exit"))
                        {
                            Globals._profilingTimerEvents_Exit.Add(profilingEvent);
                            inexit++;
                        }
                        else if (profilingEvent.Details.Stacktrace.Any(x => x.Symbol.Name.Contains("std::thread::_Invoke")))
                        {
                            ulong threadid = profilingEvent.Details.Thread;
                            if (!Globals._profilingTimerEvents_Threads.ContainsKey(threadid))
                            {
                                Globals._profilingTimerEvents_Threads.Add(threadid, new List<ProfilingTimerEvent>());
                            }
                            Globals._profilingTimerEvents_Threads[threadid].Add(profilingEvent);
                            inThreads++;
                        }
                        else
                        {
                            none++;
                        }
                    }
    
                }
            }
            Globals._profilingTimerEvents_Main.Sort((x, y) => x.Details.Timestamp.CompareTo(y.Details.Timestamp));
            Globals._profilingTimerEvents_Init.Sort((x, y) => x.Details.Timestamp.CompareTo(y.Details.Timestamp));
            Globals._profilingTimerEvents_Exit.Sort((x, y) => x.Details.Timestamp.CompareTo(y.Details.Timestamp));
            foreach (var thread in Globals._profilingTimerEvents_Threads)
            {

                thread.Value.Sort((x, y) => x.Details.Timestamp.CompareTo(y.Details.Timestamp));
            }

            //}

            //foreach (var threadcnt in Globals._profilingTimerEvents_Threads)
            //{
            //    Globals._functionStructure_threads.Add(threadcnt.Key, FunctionStructure.WalkStructure(threadcnt.Value));
            //}
            ApplicationConfiguration.Initialize();
            Globals.form1 = new();
            Application.Run(Globals.form1);
        }
    }
}