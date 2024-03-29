/*
Copyright (C) 2012  noname120

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef STATE_H_
#define STATE_H_

#include "core.h"
#include "var.h"		// TIFILE

typedef struct apphdr {
	TCHAR name[12];
	u_int page, page_count;
} apphdr_t;

typedef struct applist {
	u_int count;
	apphdr_t apps[96];
} applist_t;

typedef struct {
	uint8_t type_ID;
	uint8_t type_ID2;
	uint8_t version;
	uint16_t address;
	uint8_t page;
	uint8_t name_len;
	uint8_t length;
	TCHAR name[9];
} symbol83P_t;

typedef struct symlist {
	symbol83P_t *programs;
	symbol83P_t *last;
	symbol83P_t symbols[512];
} symlist_t;

#define pTemp			0x982E
#define progPtr			0x9830
#define symTable		0xFE66

typedef struct upages {
	u_int start, end;
} upages_t;

#define circ10(z) ((((u_char) z) < 10) ? ((z) + 1) % 10 : (z))
#define tAns	0x72

void state_build_applist(CPU_t *, applist_t *);
void state_userpages(CPU_t *, upages_t *);
symlist_t* state_build_symlist_83P(CPU_t *, symlist_t *);
TCHAR *GetRealAns(CPU_t*);
TCHAR *Symbol_Name_to_String(symbol83P_t *, TCHAR *);
TCHAR *App_Name_to_String(apphdr_t *, TCHAR *);

#endif /*STATE_H_*/
