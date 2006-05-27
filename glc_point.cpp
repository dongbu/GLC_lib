/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005-2006 Laurent Ribon (laumaya@users.sourceforge.net)
 Version 0.9.6, packaged on June, 2006.

 http://glc-lib.sourceforge.net

 GLC-lib is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 GLC-lib is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with GLC-lib; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*****************************************************************************/

//! \file glc_point.cpp implementation of the GLC_Point class.

#include "glc_point.h"


//////////////////////////////////////////////////////////////////////
// Constructor Destructor
//////////////////////////////////////////////////////////////////////


GLC_Point::GLC_Point(const GLC_Vector4d &VectSetCoord, const char *pName, const GLfloat *pColor)
:GLC_Geometry(pName, pColor), m_VectCoord(VectSetCoord)
{
	
}
//! Construct an GLC_Point
GLC_Point::GLC_Point(double x, double y, double z, const char *pName, const GLfloat *pColor)
:GLC_Geometry(pName, pColor), m_VectCoord(x, y, z)
{
}

//////////////////////////////////////////////////////////////////////
// Get Functions
//////////////////////////////////////////////////////////////////////
// return the point bounding box
GLC_BoundingBox* GLC_Point::getBoundingBox(void) const
{
	GLC_BoundingBox* pBoundingBox= new GLC_BoundingBox();
	
	GLC_Vector3d lower(m_VectCoord.GetX() - EPSILON,
						 m_VectCoord.GetY() - EPSILON,
						  m_VectCoord.GetZ() - EPSILON);
	GLC_Vector3d upper(m_VectCoord.GetX() + EPSILON,
						 m_VectCoord.GetY() + EPSILON,
						  m_VectCoord.GetZ() + EPSILON);
	pBoundingBox->combine(lower);
	pBoundingBox->combine(upper);
	
    
    pBoundingBox->transform(m_MatPos);	
	return pBoundingBox;	
}

//////////////////////////////////////////////////////////////////////
// OpenGL Functions
//////////////////////////////////////////////////////////////////////

void GLC_Point::GlDraw(void)
{
	// Point Display
	glBegin(GL_POINTS);
		glVertex3dv(m_VectCoord.Return_dVect());
	glEnd();
}

void GLC_Point::GlPropGeom(void)
{
		// Change current Matrix
		glMultMatrixd(m_MatPos.Return_dMat());
		
		// Disable lighting
		glDisable(GL_LIGHTING);
		// Disable blending
		glDisable(GL_BLEND);

		glColor4fv(GetfRGBA());			// Sa Couleur
		glPointSize(GetThickness());	// Son Epaisseur
}

