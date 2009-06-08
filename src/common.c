/*****************************************************************************/
/*  LibreDWG - Free DWG library                                              */
/*  http://code.google.com/p/libredwg/                                       */
/*                                                                           */
/*    based on LibDWG - Free DWG read-only library                           */
/*    http://sourceforge.net/projects/libdwg                                 */
/*    originally written by Felipe Castro <felipo at users.sourceforge.net>  */
/*                                                                           */
/*  Copyright (C) 2008, 2009 Free Software Foundation, Inc.                  */
/*  Copyright (C) 2009 Felipe Sanches <jucablues@users.sourceforge.net>      */
/*                                                                           */
/*  This library is free software, licensed under the terms of the GNU       */
/*  General Public License as published by the Free Software Foundation,     */
/*  either version 3 of the License, or (at your option) any later version.  */
/*  You should have received a copy of the GNU General Public License        */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.    */
/*****************************************************************************/

#include "common.h"
#include "stdio.h"

unsigned char *
dwg_sentinel (Dwg_Sentinel kiu_sentinel)
{
	static unsigned char gdst[9][16] = {
		{0x95, 0xA0, 0x4E, 0x28, 0x99, 0x82, 0x1A, 0xE5, 0x5E, 0x41, 0xE0, 0x5F, 0x9D, 0x3A,
		 0x4D, 0x00},
		{0x1F, 0x25, 0x6D, 0x07, 0xD4, 0x36, 0x28, 0x28, 0x9D, 0x57, 0xCA, 0x3F, 0x9D, 0x44,
		 0x10, 0x2B},
		{0xE0, 0xDA, 0x92, 0xF8, 0x2B, 0xc9, 0xD7, 0xD7, 0x62, 0xA8, 0x35, 0xC0, 0x62, 0xBB,
		 0xEF, 0xD4},
		{0xCF, 0x7B, 0x1F, 0x23, 0xFD, 0xDE, 0x38, 0xA9, 0x5F, 0x7C, 0x68, 0xB8, 0x4E, 0x6D,
		 0x33, 0x5F},
		{0x30, 0x84, 0xE0, 0xDC, 0x02, 0x21, 0xC7, 0x56, 0xA0, 0x83, 0x97, 0x47, 0xB1, 0x92,
		 0xCC, 0xA0},
		{0x8D, 0xA1, 0xC4, 0xB8, 0xC4, 0xA9, 0xF8, 0xC5, 0xC0, 0xDC, 0xF4, 0x5F, 0xE7, 0xCF,
		 0xB6, 0x8A},
		{0x72, 0x5L, 0x3B, 0x47, 0x3B, 0x56, 0x07, 0x3A, 0x3F, 0x23, 0x0B, 0xA0, 0x18, 0x30,
		 0x49, 0x75},
		{0xD4, 0x7B, 0x21, 0xCE, 0x28, 0x93, 0x9F, 0xBF, 0x53, 0x24, 0x40, 0x09, 0x12, 0x3C,
		 0xAA, 0x01},
		{0x2B, 0x84, 0xDE, 0x31, 0xD7, 0x6C, 0x60, 0x40, 0xAC, 0xDB, 0xBF, 0xF6, 0xED, 0xC3,
		 0x55, 0xFE}
	};

	return (gdst[kiu_sentinel]);
}

char version_codes[7][7] = {"------","AC1012","AC1014","AC1015","AC1018","AC1021","------"};

/**
 * Mapigi la pozicion de variablo aperanta en la kap-variablo sekcio kaj ties tipo
 */
Dwg_Datenero_Type
dwg_var_map (Dwg_Version_Type version, int index)
{

	static int map[] = {
//R2007 Only:
			R_2007, R_2007, DWG_DT_RL,	
//Common:
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_T,
			R_BEFORE, R_AFTER, DWG_DT_T,
			R_BEFORE, R_AFTER, DWG_DT_T,
			R_BEFORE, R_AFTER, DWG_DT_T,
			R_BEFORE, R_AFTER, DWG_DT_BL,
			R_BEFORE, R_AFTER, DWG_DT_BL,
//R13-R14 Only:
			R_13, R_14, DWG_DT_BS,
//Pre-2004 Only:
			R_BEFORE, R_2000, DWG_DT_H,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
//R13-R14 Only:
			R_13, R_14, DWG_DT_B,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,			
//R13-R14 Only:
			R_13, R_14, DWG_DT_B,
//R2004+:
			R_2004, R_AFTER, DWG_DT_B,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
//R13-R14 Only:
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
//R13-R14 Only:
			R_13, R_14, DWG_DT_B,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
//R13-R14 Only:
			R_13, R_14, DWG_DT_B,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_B,
			R_BEFORE, R_AFTER, DWG_DT_BS,
//R13-R14 Only:
			R_13, R_14, DWG_DT_BS,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
//R13-R14 Only:
			R_13, R_14, DWG_DT_BS,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_BS,
//R13-R14 Only:
			R_13, R_14, DWG_DT_BS,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_BS,
//R13-R14 Only:
			R_13, R_14, DWG_DT_BS,
//R2004+:
			R_2004, R_AFTER, DWG_DT_BL,
			R_2004, R_AFTER, DWG_DT_BL,
			R_2004, R_AFTER, DWG_DT_BL,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BS,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_T,
			R_BEFORE, R_AFTER, DWG_DT_BL,
			R_BEFORE, R_AFTER, DWG_DT_BL,
			R_BEFORE, R_AFTER, DWG_DT_BL,
			R_BEFORE, R_AFTER, DWG_DT_BL,
//R2004+:
			R_2004, R_AFTER, DWG_DT_BL,
			R_2004, R_AFTER, DWG_DT_BL,
			R_2004, R_AFTER, DWG_DT_BL,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_BL,
			R_BEFORE, R_AFTER, DWG_DT_BL,
			R_BEFORE, R_AFTER, DWG_DT_BL,
			R_BEFORE, R_AFTER, DWG_DT_BL,
			R_BEFORE, R_AFTER, DWG_DT_CMC,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
//R2007+ Only:
			R_2007, R_AFTER, DWG_DT_H,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_BD,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_2RD,
			R_BEFORE, R_AFTER, DWG_DT_2RD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_H,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_2RD,
			R_BEFORE, R_AFTER, DWG_DT_2RD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_3BD,
			R_BEFORE, R_AFTER, DWG_DT_H,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_3BD,
			R_2000, R_AFTER, DWG_DT_T,
			R_2000, R_AFTER, DWG_DT_T,
//R13-R14 Only:
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_B,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_RC,
			R_13, R_14, DWG_DT_BS,
			R_13, R_14, DWG_DT_BS,
			R_13, R_14, DWG_DT_BS,
			R_13, R_14, DWG_DT_BS,
			R_13, R_14, DWG_DT_BS,
			R_13, R_14, DWG_DT_BS,
			R_13, R_14, DWG_DT_H,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
//R2007+ Only:
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BS,
			R_2007, R_AFTER, DWG_DT_CMC,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
//R2007+ Only:
			R_2007, R_AFTER, DWG_DT_BS,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
			R_BEFORE, R_AFTER, DWG_DT_BD,
//R13-R14 Only:
			R_13, R_14, DWG_DT_T,
			R_13, R_14, DWG_DT_T,
			R_13, R_14, DWG_DT_T,
			R_13, R_14, DWG_DT_T,
			R_13, R_14, DWG_DT_T,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_BD,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_CMC,
			R_BEFORE, R_AFTER, DWG_DT_CMC,
			R_BEFORE, R_AFTER, DWG_DT_CMC,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_B,
			R_2000, R_AFTER, DWG_DT_BS,
//R2007+ Only:
			R_2007, R_AFTER, DWG_DT_B,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_H,
//R2007+ Only:
			R_2007, R_AFTER, DWG_DT_H,
			R_2007, R_AFTER, DWG_DT_H,
			R_2007, R_AFTER, DWG_DT_H,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
//R13-R15 Only:
			R_13, R_2000, DWG_DT_H,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
//R2000+ Only:
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_T,
			R_2000, R_AFTER, DWG_DT_T,
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_H,
//R2004+:
			R_2004, R_AFTER, DWG_DT_H,
			R_2004, R_AFTER, DWG_DT_H,
//R2007+:
			R_2007, R_AFTER, DWG_DT_H,
//R2000+:
			R_2000, R_AFTER, DWG_DT_BL,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_BS,
			R_2000, R_AFTER, DWG_DT_H,
			R_2000, R_AFTER, DWG_DT_T,
			R_2000, R_AFTER, DWG_DT_T,
//R2004+:
			R_2004, R_AFTER, DWG_DT_RC,
			R_2004, R_AFTER, DWG_DT_RC,
			R_2004, R_AFTER, DWG_DT_RC,
			R_2004, R_AFTER, DWG_DT_RC,
			R_2004, R_AFTER, DWG_DT_RC,
			R_2004, R_AFTER, DWG_DT_RC,
			R_2004, R_AFTER, DWG_DT_BS,
			R_2004, R_AFTER, DWG_DT_BS,
			R_2004, R_AFTER, DWG_DT_RC,
			R_2004, R_AFTER, DWG_DT_RC,
			R_2004, R_AFTER, DWG_DT_T,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
			R_BEFORE, R_AFTER, DWG_DT_H,
//R2007+:
			R_2007, R_AFTER, DWG_DT_B,
			R_2007, R_AFTER, DWG_DT_BL,
			R_2007, R_AFTER, DWG_DT_BL,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_RC,
			R_2007, R_AFTER, DWG_DT_RC,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BS,
			R_2007, R_AFTER, DWG_DT_RC,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BD,
			R_2007, R_AFTER, DWG_DT_BL,
			R_2007, R_AFTER, DWG_DT_RC,
			R_2007, R_AFTER, DWG_DT_RC,
			R_2007, R_AFTER, DWG_DT_RC,
			R_2007, R_AFTER, DWG_DT_RC,
			R_2007, R_AFTER, DWG_DT_B,
			R_2007, R_AFTER, DWG_DT_CMC,
			R_2007, R_AFTER, DWG_DT_H,
			R_2007, R_AFTER, DWG_DT_H,
			R_2007, R_AFTER, DWG_DT_H,
			R_2007, R_AFTER, DWG_DT_RC,
			R_2007, R_AFTER, DWG_DT_BD,
//R14+:
			R_14, R_AFTER, DWG_DT_BS,
			R_14, R_AFTER, DWG_DT_BS,
			R_14, R_AFTER, DWG_DT_BS,
			R_14, R_AFTER, DWG_DT_BS,
//Common:
			R_BEFORE, R_AFTER, DWG_DT_RS
};

    int i, res=0;

    for (i=0;i<index;i++, res+=3){
        while( (map[res]!=R_BEFORE && version<map[res]) || (map[res+1]!=R_AFTER && version>map[res+1]) ){
            res+=3;
        }
    }

    while( (map[res]!=R_BEFORE && version<map[res]) || (map[res+1]!=R_AFTER && version>map[res+1]) ){
        res+=3;
    }

	return (map[res+2]);
}


