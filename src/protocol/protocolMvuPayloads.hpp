/*
* Copyright (C) 2016-2018, L-Acoustics and its contributors

* This file is part of LA_avdecc.

* LA_avdecc is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* LA_avdecc is distributed in the hope that it will be usefu_state,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.

* You should have received a copy of the GNU Lesser General Public License
* along with LA_avdecc.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
* @file protocolMvuPayloads.hpp
* @author Christophe Calmejane
*/

#pragma once

#include "la/avdecc/memoryBuffer.hpp"
#include "la/avdecc/internals/serialization.hpp"
#include "la/avdecc/internals/entityModel.hpp"
#include "protocolMvuPayloadSizes.hpp"
#if defined(ENABLE_AVDECC_CUSTOM_ANY)
#include "la/avdecc/internals/any.hpp"
#else // !ENABLE_AVDECC_CUSTOM_ANY
#include <any>
#endif // ENABLE_AVDECC_CUSTOM_ANY
#include <cstdint>
#include <tuple>

namespace la
{
namespace avdecc
{
namespace protocol
{
namespace mvuPayload
{

class IncorrectPayloadSizeException final : public Exception
{
public:
	IncorrectPayloadSizeException() : Exception("Incorrect payload size") {}
};

// All serialization methods might throw a std::invalid_argument if serialization goes wrong
// All deserialization methods might throw a la::avdecc:Exception if deserialization goes wrong

/** GET_MILAN_INFO Command - Milan Clause 7.4.1 */
Serializer<AecpMvuGetMilanInfoCommandPayloadSize> serializeGetMilanInfoCommand(entity::model::ConfigurationIndex const configurationIndex);
std::tuple<entity::model::ConfigurationIndex> deserializeGetMilanInfoCommand(MvuAecpdu::Payload const& payload);

/** GET_MILAN_INFO Response - Milan Clause 7.4.1 */
Serializer<AecpMvuGetMilanInfoResponsePayloadSize> serializeGetMilanInfoResponse(entity::model::ConfigurationIndex const configurationIndex, std::uint32_t const protocolVersion, MvuFeaturesFlags const featuresFlags, std::uint32_t const certificationVersion);
std::tuple<entity::model::ConfigurationIndex, std::uint32_t, MvuFeaturesFlags, std::uint32_t> deserializeGetMilanInfoResponse(MvuAecpdu::Payload const& payload);


} // namespace mvuPayload
} // namespace protocol
} // namespace avdecc
} // namespace la
