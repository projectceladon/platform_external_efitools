/*
 * Copyright (C) 2008 Tobias Brunner
 * Copyright (C) 2007 Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include "typedefs.h"
#include "enumerator.h"

/**
 * Implementation of enumerator_create_empty().enumerate
 */
static bool enumerate_empty(enumerator_t *enumerator, ...)
{
	return FALSE;
}

/**
 * See header
 */
enumerator_t* enumerator_create_empty(void)
{
	enumerator_t *this = malloc_thing(enumerator_t);
	this->enumerate = enumerate_empty;
	this->destroy = (void*)free;
	return this;
}
