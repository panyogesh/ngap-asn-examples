/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "/home/vagrant/magma/lte/gateway/c/core/oai/tasks/ngap/messages/asn1/r16/r16.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -gen-PER -D /home/vagrant/build/c/core/oai/tasks/ngap/r16`
 */

#ifndef	_Ngap_AMFRegionID_H_
#define	_Ngap_AMFRegionID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Ngap_AMFRegionID */
typedef BIT_STRING_t	 Ngap_AMFRegionID_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_Ngap_AMFRegionID_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_Ngap_AMFRegionID;
asn_struct_free_f Ngap_AMFRegionID_free;
asn_struct_print_f Ngap_AMFRegionID_print;
asn_constr_check_f Ngap_AMFRegionID_constraint;
ber_type_decoder_f Ngap_AMFRegionID_decode_ber;
der_type_encoder_f Ngap_AMFRegionID_encode_der;
xer_type_decoder_f Ngap_AMFRegionID_decode_xer;
xer_type_encoder_f Ngap_AMFRegionID_encode_xer;
oer_type_decoder_f Ngap_AMFRegionID_decode_oer;
oer_type_encoder_f Ngap_AMFRegionID_encode_oer;
per_type_decoder_f Ngap_AMFRegionID_decode_uper;
per_type_encoder_f Ngap_AMFRegionID_encode_uper;
per_type_decoder_f Ngap_AMFRegionID_decode_aper;
per_type_encoder_f Ngap_AMFRegionID_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _Ngap_AMFRegionID_H_ */
#include <asn_internal.h>
