/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <p2world.h>
#include <p2body.h>

p2World::~p2World()
{
}

p2World::p2World(p2Vec2 gravity) :	m_Gravity(gravity)
{

}

void p2World::Step(float dt)
{
	for (auto body : m_BodyList)
	{
		if (body->GetType() != p2BodyType::STATIC)
		{

		/* ->PlaneteClassTest et balanc� dans le body via AddForce.
		//Force calculus
		p2Vec2 deltaPos = p2Vec2(400.0f, 400.0f) - body->GetPosition();
		p2Vec2 forceGravitation = deltaPos.Normalized();
		//forceGravitation *= SUN_MASS * body->GetMass() / deltaPos.LenghSquared();
		*/

			//Acceleration calculus
			p2Vec2 acceleration = m_Gravity;
			acceleration *= body->GetGravityScale() / body->GetMass();

			//Kinematic Resolution
			p2Vec2 deltaV = acceleration * dt;

			p2Vec2 newLinearVel = deltaV + body->GetLinearVelocity();
			body->SetLinearVelocity(newLinearVel);
			body->SetPosition(acceleration * 0.5f * dt * dt + newLinearVel * dt + body->GetPosition());
		}
	}
}

p2Body * p2World::CreateBody(p2BodyDef* bodyDef)
{
	p2Body* body = new p2Body(bodyDef);
	m_BodyList.push_back(body);
	return body;
}

void p2World::RemoveBody(p2Body * body)
{
	m_BodyList.remove(body);
	
}

void p2World::SetContactListener(p2ContactListener * contactListener)
{
	this->m_ContactListener = contactListener;
}
