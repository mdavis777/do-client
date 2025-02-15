// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#include "do_download_property.h"

#include "do_download_property_internal.h"
#include "do_errors.h"

namespace msdod = microsoft::deliveryoptimization::details;

namespace microsoft
{
namespace deliveryoptimization
{

download_property_value::download_property_value()
{
    _val = std::make_shared<msdod::CDownloadPropertyValueInternal>();
}

#if defined(DO_ENABLE_EXCEPTIONS)
download_property_value download_property_value::make(const std::string& val)
{
    download_property_value out;
    throw_if_fail(make_nothrow(val, out));
    return out;
}

download_property_value download_property_value::make(uint32_t val)
{
    download_property_value out;
    throw_if_fail(make_nothrow(val, out));
    return out;
}

download_property_value download_property_value::make(uint64_t val)
{
    download_property_value out;
    throw_if_fail(make_nothrow(val, out));
    return out;
}

download_property_value download_property_value::make(bool val)
{
    download_property_value out;
    throw_if_fail(make_nothrow(val, out));
    return out;
}

download_property_value download_property_value::make(std::vector<unsigned char>& val)
{
    download_property_value out;
    throw_if_fail(make_nothrow(val, out));
    return out;
}

download_property_value download_property_value::make(const status_callback_t& val)
{
    download_property_value out;
    throw_if_fail(make_nothrow(val, out));
    return out;
}

void download_property_value::as(bool& val) const
{
    throw_if_fail(_val->As(val));
};

void download_property_value::as(uint32_t& val) const
{
    throw_if_fail(_val->As(val));
};

void download_property_value::as(uint64_t& val) const
{
    throw_if_fail(_val->As(val));
};

void download_property_value::as(std::string& val) const
{
    throw_if_fail(_val->As(val));
};

void download_property_value::as(status_callback_t& val) const
{
    throw_if_fail(_val->As(val));
};

void download_property_value::as(std::vector<unsigned char>& val) const
{
    throw_if_fail(_val->As(val));
}
#endif

std::error_code download_property_value::make_nothrow(const std::string& val, download_property_value& out)
{
    download_property_value temp;
    std::error_code code = temp._val->Init(val);
    DO_RETURN_IF_FAILED(code);

    out = temp;
    return DO_OK;
}

std::error_code download_property_value::make_nothrow(uint32_t val, download_property_value& out)
{
    download_property_value temp;
    std::error_code code = temp._val->Init(val);
    DO_RETURN_IF_FAILED(code);

    out = temp;
    return DO_OK;
}

std::error_code download_property_value::make_nothrow(uint64_t val, download_property_value& out)
{
    download_property_value temp;
    std::error_code code = temp._val->Init(val);
    DO_RETURN_IF_FAILED(code);

    out = temp;
    return DO_OK;
}

std::error_code download_property_value::make_nothrow(bool val, download_property_value& out)
{
    download_property_value temp;
    std::error_code code = temp._val->Init(val);
    DO_RETURN_IF_FAILED(code);

    out = temp;
    return DO_OK;
}

std::error_code download_property_value::make_nothrow(std::vector<unsigned char>& val, download_property_value& out)
{
    download_property_value temp;
    std::error_code code = temp._val->Init(val);
    DO_RETURN_IF_FAILED(code);

    out = temp;
    return DO_OK;
}

std::error_code download_property_value::make_nothrow(const status_callback_t& val, download_property_value& out)
{
    download_property_value temp;
    std::error_code code = temp._val->Init(val);
    DO_RETURN_IF_FAILED(code);

    out = temp;
    return DO_OK;
}

std::error_code download_property_value::as_nothrow(bool& val) const noexcept
{
    return _val->As(val);
};

std::error_code download_property_value::as_nothrow(uint32_t& val) const noexcept
{
    return _val->As(val);
};

std::error_code download_property_value::as_nothrow(uint64_t& val) const noexcept
{
    return _val->As(val);
};

std::error_code download_property_value::as_nothrow(std::string& val) const noexcept
{
    return _val->As(val);
};

std::error_code download_property_value::as_nothrow(std::vector<unsigned char>& val) const noexcept
{
    return _val->As(val);
}

std::error_code download_property_value::as_nothrow(status_callback_t& val) const noexcept
{
    return _val->As(val);
};

} // deliveryoptimization
} // microsoft

