
#ifndef ENSSIMPLE_H
#define ENSSIMPLE_H

/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

#include "ensfeature.h"

AJ_BEGIN_DECLS




/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */

/* @const EnsPSimplefeatureadaptor ********************************************
**
** Ensembl Simple Feature Adaptor.
** Defined as an alias in EnsPFeatureadaptor.
**
**
** #cc Bio::EnsEMBL::DBSQL::SimpleFeatureAdaptor
** ##
******************************************************************************/

#define EnsPSimplefeatureadaptor EnsPFeatureadaptor




/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */

/* @data EnsPSimplefeature ****************************************************
**
** Ensembl Simple Feature.
**
** @alias EnsSSimplefeature
** @alias EnsOSimplefeature
**
** @attr Use [ajuint] Use counter
** @cc Bio::EnsEMBL::Storable
** @attr Identifier [ajuint] SQL database-internal identifier
** @attr Adaptor [EnsPSimplefeatureadaptor] Ensembl Simple Feature Adaptor
** @cc Bio::EnsEMBL::Feature
** @attr Feature [EnsPFeature] Ensembl Feature
** @cc Bio::EnsEMBL::Simplefeature
** @attr Displaylabel [AjPStr] Display label
** @attr Score [double] Score
** @@
******************************************************************************/

typedef struct EnsSSimplefeature
{
    ajuint Use;
    ajuint Identifier;
    EnsPSimplefeatureadaptor Adaptor;
    EnsPFeature Feature;
    AjPStr Displaylabel;
    double Score;
} EnsOSimplefeature;

#define EnsPSimplefeature EnsOSimplefeature*




/* ==================================================================== */
/* ======================= public functions =========================== */
/* ==================================================================== */

/*
** Prototype definitions
*/

/* Ensembl Simple Feature */

EnsPSimplefeature ensSimplefeatureNewCpy(const EnsPSimplefeature object);

EnsPSimplefeature ensSimplefeatureNewIni(EnsPSimplefeatureadaptor pfa,
                                         ajuint identifier,
                                         EnsPFeature feature,
                                         AjPStr label,
                                         double score);

EnsPSimplefeature ensSimplefeatureNewRef(EnsPSimplefeature sf);

void ensSimplefeatureDel(EnsPSimplefeature* Psf);

EnsPSimplefeatureadaptor ensSimplefeatureGetAdaptor(
    const EnsPSimplefeature sf);

AjPStr ensSimplefeatureGetDisplaylabel(
    const EnsPSimplefeature sf);

EnsPFeature ensSimplefeatureGetFeature(
    const EnsPSimplefeature sf);

ajuint ensSimplefeatureGetIdentifier(
    const EnsPSimplefeature sf);

double ensSimplefeatureGetScore(
    const EnsPSimplefeature sf);

AjBool ensSimplefeatureSetAdaptor(EnsPSimplefeature sf,
                                  EnsPSimplefeatureadaptor sfa);

AjBool ensSimplefeatureSetDisplaylabel(EnsPSimplefeature sf, AjPStr label);

AjBool ensSimplefeatureSetFeature(EnsPSimplefeature sf, EnsPFeature feature);

AjBool ensSimplefeatureSetIdentifier(EnsPSimplefeature sf, ajuint identifier);

AjBool ensSimplefeatureSetScore(EnsPSimplefeature sf, double score);

AjBool ensSimplefeatureTrace(const EnsPSimplefeature sf, ajuint level);

size_t ensSimplefeatureCalculateMemsize(const EnsPSimplefeature sf);

AjBool ensListSimplefeatureSortStartAscending(AjPList sfs);

AjBool ensListSimplefeatureSortStartDescending(AjPList sfs);

/* Ensembl Simple Feature Adaptor */

EnsPSimplefeatureadaptor ensRegistryGetSimplefeatureadaptor(
    EnsPDatabaseadaptor dba);

EnsPSimplefeatureadaptor ensSimplefeatureadaptorNew(
    EnsPDatabaseadaptor dba);

void ensSimplefeatureadaptorDel(EnsPSimplefeatureadaptor* Psfa);

EnsPDatabaseadaptor ensSimplefeatureadaptorGetDatabaseadaptor(
    EnsPSimplefeatureadaptor sfa);

AjBool ensSimplefeatureadaptorFetchAllbyAnalysisname(
    EnsPSimplefeatureadaptor sfa,
    const AjPStr anname,
    AjPList sfs);

AjBool ensSimplefeatureadaptorFetchAllbySlice(EnsPSimplefeatureadaptor sfa,
                                              EnsPSlice slice,
                                              const AjPStr anname,
                                              AjPList sfs);

AjBool ensSimplefeatureadaptorFetchAllbySlicescore(
    EnsPSimplefeatureadaptor sfa,
    EnsPSlice slice,
    double score,
    const AjPStr anname,
    AjPList sfs);

/*
** End of prototype definitions
*/




AJ_END_DECLS

#endif /* !ENSSIMPLE_H */