/*
 * position3D.hpp
 *
 *  Created on: Dec 12, 2023
 *      Author: KaDzejoo
 */

#ifndef POSITION3D_HPP_
#define POSITION3D_HPP_

/*
 *
 */
class position3D
{
	public:
		position3D( );
		int getX( ) const;
		void setX(int x);
		int getY( ) const;
		void setY(int y);
		int getZ( ) const;
		void setZ(int z);

	private:
		int x, y, z;

};

#endif /* POSITION3D_HPP_ */
