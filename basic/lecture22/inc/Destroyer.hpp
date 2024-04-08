#pragma once
#include <SpaceObject.hpp>

namespace mt
{
	class Destroyer : public SpaceObject
	{
	public:
		Destroyer() = default;
		virtual ~Destroyer() {}

		void Attack() override
		{
			std::cout << "Destroyer Attack" << m_x << std::endl;
		}

		void SpecialAbility() override
		{
			std::cout << "Destroyer Special Ability" << std::endl;
		}

		void Test() {}
	};
}
