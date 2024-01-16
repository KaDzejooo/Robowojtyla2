/*
 * position3D.cpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#include "position3D.hpp"

position3D::position3D(int x, int y,int z, int phi ):
_x(x), _y(y), _z(z), _phi(phi)
{
	

}

int position3D::getX( ) const
{
	return _x;
}

void position3D::setX(int x)
{
	this->_x = x;
}

int position3D::getY( ) const
{
	return _y;
}

void position3D::setY(int y)
{
	this->_y = y;
}

int position3D::getZ( ) const
{
	return _z;
}

void position3D::setZ(int z)
{
	this->_z = z;
}

int position3D::getPhi( ) const
{
	return _phi;
}

void position3D::setPhi(int phi)
{
	this->_phi = phi;
}

position3D::position3D( )
{
}
