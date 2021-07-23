#pragma once

#include <functional>
#include <string>
#include <gsl/span>

namespace microsoft
{
namespace deliveryoptimization
{

class download;

enum class download_property
{
    id,                             // std::string
    uri,                            // std::string
    catalog_id,                     // std::string
    caller_name,                    // std::string
    download_file_path,             // std::string
    http_custom_headers,            // std::string
    cost_policy,                    // uint32
    security_flags,                 // uint32
    callback_freq_percent,          // uint32
    callback_freq_seconds,          // uint32
    no_progress_timeout_seconds,    // uint32
    use_foreground_priority,        // bool
    blocking_mode,                  // bool
    callback_interface,             // void*, but used for storing lambda expressions
    stream_interface,               // void*
    security_context,               // byte array
    network_token,                  // bool
    correlation_vector,             // std::string
    decryption_info,                // std::string
    integrity_check_info,           // std::string
    integrity_check_mandatory,      // boolean
    total_size_bytes,               // uint64
    // Fe and beyond
    disallow_on_cellular,           // bool
    http_custom_auth_headers,       // std::string
};

class download_property_value
{

public:
    using stream_callback_t = std::function<void(download&, gsl::span<unsigned char>)>;

    download_property_value() = default;
    explicit download_property_value(const stream_callback_t& val) :
        _streamCallback(val)
    {
    }

    explicit download_property_value(const std::string& val) :
        _stringVal(val)
    {
    }

    void as(stream_callback_t& val) const
    {
        val = _streamCallback;
    }

    void as(std::string& val) const
    {
        val = _stringVal;
    }

private:
    stream_callback_t _streamCallback;
    std::string _stringVal;
};

} // namespace deliveryoptimization
} // namespace microsoft
