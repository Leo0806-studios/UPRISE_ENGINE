using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UPRISE_PROFILER_APPLICATION
{
    internal class FunctionStructure
    {
        public bool isRoot;
        public string name="";
        public ProfilingTimerEvent? ProfilingEvent;
    public List<FunctionStructure>? Children;
        public FunctionStructure? Parent;
        public static FunctionStructure WalkStructure( List<ProfilingTimerEvent> _Events)
        {
            float proggresStepp = 100/ _Events.Count;
            float progress = 0; 
            List<ProfilingTimerEvent> LocalEvents = new List<ProfilingTimerEvent>();
            LocalEvents.AddRange(_Events);
            LocalEvents.Sort((x, y) => x.Details.Timestamp.CompareTo(y.Details.Timestamp));
            LocalEvents.Reverse();
            int _eventCount = LocalEvents.Count-1;
            FunctionStructure? root = null;
            ProfilingTimerEvent? lastEvent = null;
            int localDepth = 0;
            lastEvent = LocalEvents[_eventCount];
            localDepth = lastEvent.Details.Stacktrace.Count;
            root = new FunctionStructure();
            root.ProfilingEvent = lastEvent;
            root.Children = new List<FunctionStructure>();
            root.name = lastEvent.Details.Function;
            LocalEvents.RemoveAt(_eventCount);
            root.isRoot = true;
            _eventCount--;
            int LastDepth = localDepth;
            FunctionStructure? current = root;
            progress += proggresStepp;
            ((Form1)Globals.form1).SetProgressbatr(progress);

            for (int i = _eventCount; i >=0; --i)
            {
                localDepth = LocalEvents[i].Details.Stacktrace.Count;
                if (localDepth > LastDepth)
                {
                    FunctionStructure? newChild = new FunctionStructure();
                    newChild.ProfilingEvent = LocalEvents[i];
                    newChild.name = LocalEvents[i].Details.Function;
                    newChild.Children = new List<FunctionStructure>();
                    newChild.Parent = current;
                    current.Children.Add(newChild);
                    current = newChild;
                    LastDepth = localDepth;
                    LocalEvents.RemoveAt(i);

                }
                else if (localDepth < LastDepth)
                {
                    int diff = LastDepth - localDepth;
                    while (diff >= 0)
                    {
                        if (!current.isRoot)
                        {
                            current = current.Parent;
                            /*//if (current.Parent.isRoot)
                            //{
                            //    if (current.Parent.Parent.isRoot)
                            //    {
                            //        current = current.Parent.Parent;
                            //    }
                            //    else
                            //    {
                            //        throw new Exception("Error in function structure.\n trying to get parrent of root");
                            //    }

                            //}*/

                        }

                        diff--;
                    }
                    FunctionStructure? newChild = new FunctionStructure();
                    newChild.ProfilingEvent = LocalEvents[i];
                    newChild.Children = new List<FunctionStructure>();
                    newChild.Parent = current;
                    newChild.ProfilingEvent = LocalEvents[i];
                    newChild.name = LocalEvents[i].Details.Function;
                    LocalEvents.RemoveAt(i);
                    current.Children.Add(newChild);
                    current = newChild;
                    LastDepth = localDepth;



                }
                else if (localDepth == LastDepth)
                {
                    if (!current.isRoot)
                    {
                        current= current.Parent;
                    }
                    FunctionStructure? newChild = new FunctionStructure();
                    newChild.ProfilingEvent = LocalEvents[i];
                    newChild.Children = new List<FunctionStructure>();
                    newChild.Parent = current;
                    newChild.name = LocalEvents[i].Details.Function;
                    current.Children.Add(newChild);
                    current = newChild;
                    LastDepth = localDepth;
                    newChild.ProfilingEvent = LocalEvents[i];
                    LocalEvents.RemoveAt(i);
                }
                else
                {
                    throw new Exception("Error in function structure.\n");
                }
                progress += proggresStepp;
                ((Form1)Globals.form1).SetProgressbatr(progress);
            }

            return root;

        }
    }
}
