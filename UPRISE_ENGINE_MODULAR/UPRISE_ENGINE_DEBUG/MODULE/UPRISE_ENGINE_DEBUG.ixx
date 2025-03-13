export module UPRISE_ENGINE_DEBUG;

export import :LOG;
export import :LOG_STREAM;

#ifdef UPRISEENGINEDEBUG_EXPORTS
import :LOG_IMPL;
import :LOG_STREAM_IMPL;
#endif // UPRISEENGINEDEBUG_EXPORTS