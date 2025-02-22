#ifndef INCLUDE_GAMEOBJECT
#include "GameObject.h"
#endif

namespace Geodash3
{
	//Player object that inherits from the GameObject class
	class Player : public GameObject
	{
		float m_gravity; //Force of gravity on the player

		Geodash3::Collider m_collider; //Box collider for the player
	public:
		bool falling = false,
			 canJump = true, //Stores if the player can jump
			 isJumping = false; //Stores if the player is jumping

		void Update(float secToDrawFrame); //Update the player object

		//Return the collider
		Geodash3::Collider getCollider();

		//Constructor
		Player(glm::vec3 pos);
	};
}
