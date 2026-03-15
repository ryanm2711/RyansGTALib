#pragma once
namespace GTA {
	class Entity {
	public:
		Entity(int ID) : m_ID(ID) {};
		~Entity() = default;

		
	private:
		enum EntityTypeInternal {
			Building = 1,
			Vehicle = 3,
			Ped = 4,
			Object = 5
		};

		int m_ID;

		Entity::EntityTypeInternal m_EntityType;
	};
}