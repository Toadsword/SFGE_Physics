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
#include <p2body.h>
#include <p2collider.h>

p2Body::p2Body()
{
}

p2Body::p2Body(p2BodyDef* bodyDef) :
	m_type(bodyDef->type),
	m_position(bodyDef->position),
	m_linearVelocity(bodyDef->linearVelocity),
	m_gravityScale(bodyDef->gravityScale),
	m_mass(bodyDef->mass)
{

}

p2Body::~p2Body()
{
}

p2Vec2 p2Body::GetLinearVelocity()
{
	return m_linearVelocity;
}

void p2Body::SetLinearVelocity(p2Vec2 velocity)
{
	this->m_linearVelocity = velocity;
}

float p2Body::GetAngularVelocity()
{
	return m_angularVelocity;
}

float p2Body::GetGravityScale()
{
	return m_gravityScale;
}

p2Vec2 p2Body::GetPosition()
{
	return m_position;
}

void p2Body::SetPosition(p2Vec2 newPos)
{
	m_position = newPos;
}

p2BodyType p2Body::GetType()
{
	return m_type;
}

float p2Body::GetMass()
{
	return m_mass;
}

p2Collider * p2Body::CreateCollider(p2ColliderDef * colliderDef)
{
	p2Collider* collider = new p2Collider(colliderDef);
	m_colliderList.push_back(collider);
	return collider;
}

void p2Body::AddForce()
{
}
