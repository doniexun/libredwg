#!/usr/bin/perl
=head1 DESCRIPTION

All Unstable, Debugging and Unhandled classnames, from CLASS.dxfname.
See F<src/classes.inc>

=cut
no strict;

# unstable/undertested.
# not enough coverage, but assumed mostly ok. field names may change.
# DXF output skipped
@unstable = qw(
  ACDBASSOCACTION
  ACDBASSOCNETWORK
  ACDBASSOCDEPENDENCY
  ACDBASSOCGEOMDEPENDENCY
  ACDBASSOCBLENDSURFACEACTIONBODY
  ACDBASSOCEXTRUDEDSURFACEACTIONBODY
  ACDBASSOCFILLETSURFACEACTIONBODY
  ACDBASSOCLOFTEDSURFACEACTIONBODY
  ACDBASSOCPATCHSURFACEACTIONBODY
  ACDBASSOCPLANESURFACEACTIONBODY
  ACDBASSOCPLANESURFACEACTIONBODY
  ACDBASSOCREVOLVEDSURFACEACTIONBODY
  ACDBASSOCSWEPTSURFACEACTIONBODY
  ACDBDETAILVIEWSTYLE
  ACDBSECTIONVIEWSTYLE
  ACSH_BREP_CLASS
  ACSH_CHAMFER_CLASS
  ACSH_CONE_CLASS
  ACSH_PYRAMID_CLASS
  ACSH_TORUS_CLASS
  ARC_DIMENSION
  DBCOLOR
  DIMASSOC
  HELIX
  LIGHT
  LIGHTLIST
  MATERIAL
  MENTALRAYRENDERSETTINGS
  OBJECT_PTR
  PLOTSETTING
  PROXY_OBJECT
  RAPIDRTRENDERSETTINGS
  RENDERSETTINGS
  SECTION_SETTINGS
  SUN
  TABLESTYLE
  SOLID_BACKGROUND
  SKYLIGHT_BACKGROUND
  GROUND_PLANE_BACKGROUND
  GRADIENT_BACKGROUND
  IMAGE_BACKGROUND
  IBL_BACKGROUND
);

@debugging = qw(
  GEOPOSITIONMARKER
  PLANESURFACE
  EXTRUDEDSURFACE
  LOFTEDSURFACE
  REVOLVEDSURFACE
  SWEPTSURFACE
  ACAD_TABLE
  TABLECONTENT
  SUNSTUDY
  VBA_PROJECT
  ACSH_EXTRUSION_CLASS
  ACSH_HISTORY_CLASS
  ACSH_LOFT_CLASS
  ACSH_REVOLVE_CLASS
  ACSH_SWEEP_CLASS
  GEOMAPIMAGE
  ACDBNAVISWORKSMODELDEF
  ACDBASSOC2DCONSTRAINTGROUP
  ACDBASSOC3POINTANGULARDIMACTIONBODY
  ACDBASSOCALIGNEDDIMACTIONBODY
  ACDBASSOCVARIABLE
  ACDBASSOCOSNAPPOINTREFACTIONPARAM
  ACDBASSOCPERSSUBENTMANAGER
  ACDBPERSSUBENTMANAGER
  ACAD_EVALUATION_GRAPH
  RENDERENVIRONMENT
  RENDERGLOBAL
  ACDB_OBJECTCONTEXTDATA_CLASS
  ACDB_ALDIMOBJECTCONTEXTDATA_CLASS
  ACDB_ANGDIMOBJECTCONTEXTDATA_CLASS
  ACDB_DMDIMOBJECTCONTEXTDATA_CLASS
  ACDB_ORDDIMOBJECTCONTEXTDATA_CLASS
  ACDB_RADIMOBJECTCONTEXTDATA_CLASS
  ACDB_RADIMLGOBJECTCONTEXTDATA_CLASS
  ACDB_BLKREFOBJECTCONTEXTDATA_CLASS
  ACDB_FCFOBJECTCONTEXTDATA_CLASS
  ACDB_LEADEROBJECTCONTEXTDATA_CLASS
  ACDB_MLEADEROBJECTCONTEXTDATA_CLASS
  ACDB_MTEXTATTRIBUTEOBJECTCONTEXTDATA_CLASS
  ACDB_MTEXTOBJECTCONTEXTDATA_CLASS
  ACDB_TEXTOBJECTCONTEXTDATA_CLASS
  DATALINK
  DATATABLE
  LAYOUTPRINTCONFIG
  ACMECOMMANDHISTORY
  ACMESCOPE
  ACMESTATEMGR
  ACDBASSOCOSNAPPOINTREFACTIONPARAM
  ACDBASSOCASMBODYACTIONPARAM
  ACDBASSOCCOMPOUNDACTIONPARAM
  ACDBASSOCEDGEACTIONPARAM
  ACDBASSOCFACEACTIONPARAM
  ACDBASSOCPATHACTIONPARAM
  ACDBASSOCVERTEXACTIONPARAM
  CSACDOCUMENTOPTIONS
  ATEXT
  RTEXT
  ACDBCURVEPATH
  ACDBMOTIONPATH
  ACDBPOINTPATH
);

@unhandled = qw (
  ACDSRECORD
  ACDSSCHEMA
  NPOCOLLECTION
  ACDBPOINTCLOUD
  RAPIDRTRENDERENVIRONMENT
  EXACXREFPANELOBJECT
  VISIBILITYGRIPENTITY
  VISIBILITYPARAMETERENTITY
  );

%unstable  = map {$_ => 1} @unstable;
%debugging = map {$_ => 1} @debugging;
%unhandled = map {$_ => 1} @unhandled;
1;
