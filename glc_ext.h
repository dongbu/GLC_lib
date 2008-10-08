/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005-2008 Laurent Ribon (laumaya@users.sourceforge.net)
 Version 1.0.0, packaged on August, 2008.

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

#ifndef GLC_EXT_H_
#define GLC_EXT_H_

#include <QtOpenGL>
#include <glext.h>

#if !defined(Q_OS_MAC)
// ARB_vertex_buffer_object
extern PFNGLBINDBUFFERARBPROC			glBindBuffer				= NULL;
extern PFNGLDELETEBUFFERSARBPROC		glDeleteBuffers				= NULL;
extern PFNGLGENBUFFERSARBPROC			glGenBuffers				= NULL;
extern PFNGLISBUFFERARBPROC				glIsBuffer					= NULL;
extern PFNGLBUFFERDATAARBPROC			glBufferData				= NULL;
extern PFNGLBUFFERSUBDATAARBPROC		glBufferSubData				= NULL;
extern PFNGLGETBUFFERSUBDATAARBPROC		glGetBufferSubData			= NULL;
extern PFNGLMAPBUFFERARBPROC			glMapBuffer					= NULL;
extern PFNGLUNMAPBUFFERARBPROC			glUnmapBuffer				= NULL;
extern PFNGLGETBUFFERPARAMETERIVARBPROC	glGetBufferParameteriv		= NULL;
extern PFNGLGETBUFFERPOINTERVARBPROC	glGetBufferPointerv			= NULL;
#endif

namespace glc
{
	//! Return true if the extension is supported
	bool extensionIsSupported(const QString&);
	
	//! Load VBO extension
	bool loadVboExtension();
};
#endif /*GLC_EXT_H_*/