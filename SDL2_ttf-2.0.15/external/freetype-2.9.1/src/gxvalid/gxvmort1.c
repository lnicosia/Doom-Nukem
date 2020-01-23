/***************************************************************************/
/*                                                                         */
/*  gxvmort1.c                                                             */
/*                                                                         */
/*    TrueTypeGX/AAT mort table validation                                 */
/*    body for type1 (Contextual Substitution) subtable.                   */
/*                                                                         */
/*  Copyright 2005-2018 by                                                 */
/*  suzuki toshiya, Masatake YAMATO, Red Hat K.K.,                         */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/

/***************************************************************************/
/*                                                                         */
/* gxvalid is derived from both gxlayout module and otvalid module.        */
/* Development of gxlayout is supported by the Information-technology      */
/* Promotion Agency(IPA), Japan.                                           */
/*                                                                         */
/***************************************************************************/


#include "gxvmort.h"


  /*************************************************************************/
  /*                                                                       */
  /* The macro FT_COMPONENT is used in trace mode.  It is an implicit      */
  /* parameter of the FT_TRACE() and FT_ERROR() macros, used to print/log  */
  /* messages during execution.                                            */
  /*                                                                       */
#undef  FT_COMPONENT
#define FT_COMPONENT  trace_gxvmort


  typedef struct  GXV_mort_subtable_type1_StateOptRec_
  {
    FT_Uint  substitutionTable;
    FT_Uint  substitutionTable_length;

  }  GXV_mort_subtable_type1_StateOptRec,
    *GXV_mort_subtable_type1_StateOptRecData;

#define GXV_MORT_SUBTABLE_TYPE1_HEADER_SIZE \
          ( GXV_STATETABLE_HEADER_SIZE + 2 )


  static void
  gxv_mort_subtable_type1_substitutionTable_load( FT_Bytes       table,
                                                  FT_Bytes       limit,
                                                  GXV_Validator  gxvalid )
  {
    FT_Bytes  p = table;

    GXV_mort_subtable_type1_StateOptRecData  optdata =
      (GXV_mort_subtable_type1_StateOptRecData)gxvalid->statetable.optdata;


    GXV_LIMIT_CHECK( 2 );
    optdata->substitutionTable = FT_NEXT_Uint( p );
  }


  static void
  gxv_mort_subtable_type1_subtable_setup( FT_Uint      table_size,
                                          FT_Uint      classTable,
                                          FT_Uint      stateArray,
                                          FT_Uint      entryTable,
                                          FT_Uint*     classTable_length_p,
                                          FT_Uint*     stateArray_length_p,
                                          FT_Uint*     entryTable_length_p,
                                          GXV_Validator  gxvalid )
  {
    FT_Uint  o[4];
    FT_Uint  *l[4];
    FT_Uint  buff[5];

    GXV_mort_subtable_type1_StateOptRecData  optdata =
      (GXV_mort_subtable_type1_StateOptRecData)gxvalid->statetable.optdata;


    o[0] = classTable;
    o[1] = stateArray;
    o[2] = entryTable;
    o[3] = optdata->substitutionTable;
    l[0] = classTable_length_p;
    l[1] = stateArray_length_p;
    l[2] = entryTable_length_p;
    l[3] = &( optdata->substitutionTable_length );

    gxv_set_length_by_uint_offset( o, l, buff, 4, table_size, gxvalid );
  }


  static void
  gxv_mort_subtable_type1_offset_to_subst_validate(
    FT_int          wordOffset,
    const FT_String*  tag,
    FT_Byte           state,
    GXV_Validator     gxvalid )
  {
    FT_Uint  substTable;
    FT_Uint  substTable_limit;

    FT_UNUSED( tag );
    FT_UNUSED( state );


    substTable =
      ((GXV_mort_subtable_type1_StateOptRec *)
       (gxvalid->statetable.optdata))->substitutionTable;
    substTable_limit =
      (FT_Uint)( substTable +
                   ((GXV_mort_subtable_type1_StateOptRec *)
                    (gxvalid->statetable.optdata))->substitutionTable_length );

    gxvalid->min_gid = (FT_Uint)( ( substTable       - wordOffset * 2 ) / 2 );
    gxvalid->max_gid = (FT_Uint)( ( substTable_limit - wordOffset * 2 ) / 2 );
    gxvalid->max_gid = (FT_Uint)( FT_MAX( gxvalid->max_gid,
                                            gxvalid->face->num_glyphs ) );

    /* XXX: check range? */

    /* TODO: min_gid & max_gid comparison with ClassTable contents */
  }


  static void
  gxv_mort_subtable_type1_entry_validate(
    FT_Byte                         state,
    FT_Uint                       flags,
    GXV_StateTable_GlyphOffsetCPtr  glyphOffset_p,
    FT_Bytes                        table,
    FT_Bytes                        limit,
    GXV_Validator                   gxvalid )
  {
#ifdef GXV_LOAD_UNUSED_VARS
    FT_Uint  setMark;
    FT_Uint  dontAdvance;
#endif
    FT_Uint  reserved;
    FT_int   markOffset;
    FT_int   currentOffset;

    FT_UNUSED( table );
    FT_UNUSED( limit );


#ifdef GXV_LOAD_UNUSED_VARS
    setMark       = (FT_Uint)(   flags >> 15            );
    dontAdvance   = (FT_Uint)( ( flags >> 14 ) & 1      );
#endif
    reserved      = (FT_Uint)(    flags        & 0x3FFF );

    markOffset    = (FT_int)( glyphOffset_p->ul >> 16 );
    currentOffset = (FT_int)( glyphOffset_p->ul       );

    if ( 0 < reserved )
    {
      GXV_TRACE(( " non-zero bits found in reserved range\n" ));
      GXV_SET_ERR_IF_PARANOID( FT_INVALID_DATA );
    }

    gxv_mort_subtable_type1_offset_to_subst_validate( markOffset,
                                                      "markOffset",
                                                      state,
                                                      gxvalid );

    gxv_mort_subtable_type1_offset_to_subst_validate( currentOffset,
                                                      "currentOffset",
                                                      state,
                                                      gxvalid );
  }


  static void
  gxv_mort_subtable_type1_substTable_validate( FT_Bytes       table,
                                               FT_Bytes       limit,
                                               GXV_Validator  gxvalid )
  {
    FT_Bytes   p = table;
    FT_Uint  num_gids = (FT_Uint)(
                 ((GXV_mort_subtable_type1_StateOptRec *)
                  (gxvalid->statetable.optdata))->substitutionTable_length / 2 );
    FT_Uint  i;


    GXV_NAME_ENTER( "validating contents of substitutionTable" );
    for ( i = 0; i < num_gids; i++ )
    {
      FT_Uint  dst_gid;


      GXV_LIMIT_CHECK( 2 );
      dst_gid = FT_NEXT_Uint( p );

      if ( dst_gid >= 0xFFFFU )
        continue;

      if ( dst_gid < gxvalid->min_gid || gxvalid->max_gid < dst_gid )
      {
        GXV_TRACE(( "substTable include a strange gid[%d]=%d >"
                    " out of define range (%d..%d)\n",
                    i, dst_gid, gxvalid->min_gid, gxvalid->max_gid ));
        GXV_SET_ERR_IF_PARANOID( FT_INVALID_GLYPH_ID );
      }
    }

    GXV_EXIT;
  }


  /*
   * subtable for Contextual glyph substitution is a modified StateTable.
   * In addition to classTable, stateArray, and entryTable, the field
   * `substitutionTable' is added.
   */
  FT_LOCAL_DEF( void )
  gxv_mort_subtable_type1_validate( FT_Bytes       table,
                                    FT_Bytes       limit,
                                    GXV_Validator  gxvalid )
  {
    FT_Bytes  p = table;

    GXV_mort_subtable_type1_StateOptRec  st_rec;


    GXV_NAME_ENTER( "mort chain subtable type1 (Contextual Glyph Subst)" );

    GXV_LIMIT_CHECK( GXV_MORT_SUBTABLE_TYPE1_HEADER_SIZE );

    gxvalid->statetable.optdata =
      &st_rec;
    gxvalid->statetable.optdata_load_func =
      gxv_mort_subtable_type1_substitutionTable_load;
    gxvalid->statetable.subtable_setup_func =
      gxv_mort_subtable_type1_subtable_setup;
    gxvalid->statetable.entry_glyphoffset_fmt =
      GXV_GLYPHOFFSET_ULONG;
    gxvalid->statetable.entry_validate_func =

      gxv_mort_subtable_type1_entry_validate;
    gxv_StateTable_validate( p, limit, gxvalid );

    gxv_mort_subtable_type1_substTable_validate(
      table + st_rec.substitutionTable,
      table + st_rec.substitutionTable + st_rec.substitutionTable_length,
      gxvalid );

    GXV_EXIT;
  }


/* END */
