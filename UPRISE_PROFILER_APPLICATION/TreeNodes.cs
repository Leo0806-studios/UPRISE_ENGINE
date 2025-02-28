// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace UPRISE_PROFILER_APPLICATION
{
    internal class TimerTreeNode : TreeNode
    {
        public ProfilingTimerEvent? ProfilingEvent;
        public ulong SelfTime;
        public ulong TotalTime;
        public TimerTreeNode(ProfilingTimerEvent? _event) : base($"{_event.Details.Function} ({_event.Details.Duration.Value} {"ns"})")
        {
            ProfilingEvent = _event;
            if (_event != null)
            {
                Text = _event.Details.Function;
            }
        }
        public ulong GetAlltimeOfChildren()
        {
            ulong time = 0;
            foreach (var child in base.Nodes)
            {
                if (child is TimerTreeNode)
                {
                    ulong Durationns = 0;
                    if (ProfilingEvent != null)
                    {
                        //switch (ProfilingEvent.Details.Duration.Unit)
                        //{
                        //    case "ns":
                                Durationns = (ProfilingEvent.Details.Duration.Value);
                        //        break;
                        //    case "us":
                        //        Durationns =(ProfilingEvent.Details.Duration.Value) * 1000;
                        //        break;
                        //    case "ms":
                        //        Durationns = (ProfilingEvent.Details.Duration.Value) * 1000000;
                        //        break;
                        //    case "s":
                        //        Durationns = (ProfilingEvent.Details.Duration.Value) * 1000000000;
                        //        break;

                        //}
                        time += Durationns;
                    }
                }
            }
            return time;
        }
        public ulong GetDurationRecursively()
        {
            ulong Durationns = 0;
            if (ProfilingEvent != null)
            {
                //switch (ProfilingEvent.Details.Duration.Unit)
                //{
                //    case "ns":
                        Durationns =ProfilingEvent.Details.Duration.Value;
                //        break;
                //    case "us":
                //        Durationns = (ulong)Math.Floor(ProfilingEvent.Details.Duration.Value) * 1000;
                //        break;
                //    case "ms":
                //        Durationns = (ulong)Math.Floor(ProfilingEvent.Details.Duration.Value) * 1000000;
                //        break;
                //    case "s":
                //        Durationns = (ulong)Math.Floor(ProfilingEvent.Details.Duration.Value) * 1000000000;
                //        break;

                //}
                foreach (var child in base.Nodes)
                {
                    if (child is TimerTreeNode)
                    {
                        Durationns += (child as TimerTreeNode).GetDurationRecursively();
                    }
                }
            }
            return Durationns;
        }

    }
}

