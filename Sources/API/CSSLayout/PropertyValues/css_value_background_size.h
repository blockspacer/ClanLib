/*
**  ClanLib SDK
**  Copyright (c) 1997-2013 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/

#pragma once

#include "../CSSDocument/css_property_value.h"
#include "../CSSDocument/css_length.h"

namespace clan
{
/// \addtogroup clanCSSLayout_PropertyValues clanCSSLayout Property Values
/// \{

class CSSValueBackgroundSize : public CSSPropertyValue
{
public:
	CSSValueBackgroundSize();
	void compute(const CSSValueBackgroundSize *parent, CSSResourceCache *layout, float em_size, float ex_size);
	std::string to_string() const;
	void apply(CSSComputedValuesUpdater *updater);

	enum Type
	{
		type_value,
		type_inherit
	} type;

	enum SizeType
	{
		size_contain,
		size_cover,
		size_values,
	};

	enum ValueType
	{
		value_type_auto,
		value_type_length,
		value_type_percentage
	};

	class Size
	{
	public:
		Size() : type(size_values), value_x(value_type_auto), value_y(value_type_auto), percentage_x(0.0f), percentage_y(0.0f) { }

		SizeType type;
		ValueType value_x, value_y;
		CSSLength length_x;
		float percentage_x;
		CSSLength length_y;
		float percentage_y;
	};

	std::vector<Size> values;
};

/// \}
}