#pragma once

namespace qf
{
	class Object {
	public:
		virtual bool IsNull() const = 0;
		virtual operator bool() const final
		{
			return IsNull();
		}
	};
};