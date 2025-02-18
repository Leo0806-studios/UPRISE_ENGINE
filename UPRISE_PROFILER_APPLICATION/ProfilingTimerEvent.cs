// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace UPRISE_PROFILER_APPLICATION
{
    internal class ProfilingEventSummary
    {
        private string _name="";
        private double _maxDuration;
        private double _minDuration;
        private double _averageDuration;
        private int _count;
        private string _file="";
        private int _line;
        private string _function="";
        public ProfilingEventSummary(string name, double duration, string file, int line, string function)
        {
            _name = name;
            _maxDuration = duration;
            _minDuration = duration;
            _averageDuration = duration;
            _count = 1;
            _file = file;
            _line = line;
            _function = function;
        }

    }
    internal class ProfilingTimerEvent
    {
        [System.Text.Json.Serialization.JsonPropertyName("Event")]
        public EventDetails Details { get; set; }



    }
    internal class EventDetails
    {
        [JsonPropertyName("timestamp")]
        public ulong Timestamp { get; set; }

        [JsonPropertyName("name")]
        public string Name { get; set; }

        [JsonPropertyName("Thread")]
        public ulong Thread { get; set; }

        [JsonPropertyName("file")]
        public string File { get; set; }

        [JsonPropertyName("function")]
        public string Function { get; set; }

        [JsonPropertyName("line")]
        public long Line { get; set; }

        [JsonPropertyName("duration")]
        public Duration Duration { get; set; }

        [JsonPropertyName("Stacktrace")]
        public List<StackTraceSymbol> Stacktrace { get; set; }


    }
    public class Duration
    {
        [JsonPropertyName("value")]
        public ulong  Value { get; set; }


    }

    public class StackTraceSymbol
    {
        [JsonPropertyName("Symbol")]
        public Symbol Symbol { get; set; }
    }

    public class Symbol
    {
        [JsonPropertyName("name")]
        public string Name { get; set; }

        [JsonPropertyName("Displacement")]
        public ulong Displacement { get; set; }
    }
}
