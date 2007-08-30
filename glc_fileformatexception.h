/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005-2006 Laurent Ribon (laumaya@users.sourceforge.net)
 Version 0.9.7, packaged on September, 2007.

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

//! \file glc_fileformatexception.h Interface for the GLC_FileFormatException class.

#ifndef GLC_FILEFORMATEXCEPTION_H_
#define GLC_FILEFORMATEXCEPTION_H_
#include "glc_exception.h"

//////////////////////////////////////////////////////////////////////
//! \class GLC_FileFormatException
/*! \brief GLC_FileFormatException : Class for all File Format ERROR
 */
//////////////////////////////////////////////////////////////////////
class GLC_FileFormatException : public GLC_Exception
{
public:
	GLC_FileFormatException(const QString &message, const QString &fileName);
	virtual ~GLC_FileFormatException() throw();
	
//////////////////////////////////////////////////////////////////////
/*! \name Get Functions*/
//@{
//////////////////////////////////////////////////////////////////////
public:	
	//! Return exception description
	virtual const char* what() const throw();
//@}
//////////////////////////////////////////////////////////////////////
// protected members
//////////////////////////////////////////////////////////////////////
protected:
	
	//! The name of the file
	QString m_FileName;
	
};

#endif /*GLC_FILEFORMATEXCEPTION_H_*/
