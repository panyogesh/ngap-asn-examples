/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "/home/vagrant/magma/lte/gateway/c/core/oai/tasks/ngap/messages/asn1/r16/r16.asn1"
 * 	`asn1c -pdu=all -fcompound-names -fno-include-deps -gen-PER -D /home/vagrant/build/c/core/oai/tasks/ngap/r16`
 */

#include "Ngap_CauseRadioNetwork.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_Ngap_CauseRadioNetwork_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_Ngap_CauseRadioNetwork_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  6,  6,  0,  44 }	/* (0..44,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_Ngap_CauseRadioNetwork_value2enum_1[] = {
	{ 0,	11,	"unspecified" },
	{ 1,	22,	"txnrelocoverall-expiry" },
	{ 2,	19,	"successful-handover" },
	{ 3,	37,	"release-due-to-ngran-generated-reason" },
	{ 4,	35,	"release-due-to-5gc-generated-reason" },
	{ 5,	18,	"handover-cancelled" },
	{ 6,	16,	"partial-handover" },
	{ 7,	52,	"ho-failure-in-target-5GC-ngran-node-or-target-system" },
	{ 8,	21,	"ho-target-not-allowed" },
	{ 9,	22,	"tngrelocoverall-expiry" },
	{ 10,	19,	"tngrelocprep-expiry" },
	{ 11,	18,	"cell-not-available" },
	{ 12,	16,	"unknown-targetID" },
	{ 13,	43,	"no-radio-resources-available-in-target-cell" },
	{ 14,	24,	"unknown-local-UE-NGAP-ID" },
	{ 15,	30,	"inconsistent-remote-UE-NGAP-ID" },
	{ 16,	35,	"handover-desirable-for-radio-reason" },
	{ 17,	22,	"time-critical-handover" },
	{ 18,	30,	"resource-optimisation-handover" },
	{ 19,	27,	"reduce-load-in-serving-cell" },
	{ 20,	15,	"user-inactivity" },
	{ 21,	29,	"radio-connection-with-ue-lost" },
	{ 22,	29,	"radio-resources-not-available" },
	{ 23,	23,	"invalid-qos-combination" },
	{ 24,	36,	"failure-in-radio-interface-procedure" },
	{ 25,	32,	"interaction-with-other-procedure" },
	{ 26,	22,	"unknown-PDU-session-ID" },
	{ 27,	18,	"unkown-qos-flow-ID" },
	{ 28,	33,	"multiple-PDU-session-ID-instances" },
	{ 29,	30,	"multiple-qos-flow-ID-instances" },
	{ 30,	63,	"encryption-and-or-integrity-protection-algorithms-not-supported" },
	{ 31,	34,	"ng-intra-system-handover-triggered" },
	{ 32,	34,	"ng-inter-system-handover-triggered" },
	{ 33,	21,	"xn-handover-triggered" },
	{ 34,	23,	"not-supported-5QI-value" },
	{ 35,	19,	"ue-context-transfer" },
	{ 36,	48,	"ims-voice-eps-fallback-or-rat-fallback-triggered" },
	{ 37,	36,	"up-integrity-protection-not-possible" },
	{ 38,	42,	"up-confidentiality-protection-not-possible" },
	{ 39,	19,	"slice-not-supported" },
	{ 40,	38,	"ue-in-rrc-inactive-state-not-reachable" },
	{ 41,	11,	"redirection" },
	{ 42,	37,	"resources-not-available-for-the-slice" },
	{ 43,	43,	"ue-max-integrity-protected-data-rate-reason" },
	{ 44,	35,	"release-due-to-cn-detected-mobility" },
	{ 45,	27,	"n26-interface-not-available" },
	{ 46,	26,	"release-due-to-pre-emption" },
	{ 47,	50,	"multiple-location-reporting-reference-ID-instances" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_Ngap_CauseRadioNetwork_enum2value_1[] = {
	11,	/* cell-not-available(11) */
	30,	/* encryption-and-or-integrity-protection-algorithms-not-supported(30) */
	24,	/* failure-in-radio-interface-procedure(24) */
	5,	/* handover-cancelled(5) */
	16,	/* handover-desirable-for-radio-reason(16) */
	7,	/* ho-failure-in-target-5GC-ngran-node-or-target-system(7) */
	8,	/* ho-target-not-allowed(8) */
	36,	/* ims-voice-eps-fallback-or-rat-fallback-triggered(36) */
	15,	/* inconsistent-remote-UE-NGAP-ID(15) */
	25,	/* interaction-with-other-procedure(25) */
	23,	/* invalid-qos-combination(23) */
	28,	/* multiple-PDU-session-ID-instances(28) */
	47,	/* multiple-location-reporting-reference-ID-instances(47) */
	29,	/* multiple-qos-flow-ID-instances(29) */
	45,	/* n26-interface-not-available(45) */
	32,	/* ng-inter-system-handover-triggered(32) */
	31,	/* ng-intra-system-handover-triggered(31) */
	13,	/* no-radio-resources-available-in-target-cell(13) */
	34,	/* not-supported-5QI-value(34) */
	6,	/* partial-handover(6) */
	21,	/* radio-connection-with-ue-lost(21) */
	22,	/* radio-resources-not-available(22) */
	41,	/* redirection(41) */
	19,	/* reduce-load-in-serving-cell(19) */
	4,	/* release-due-to-5gc-generated-reason(4) */
	44,	/* release-due-to-cn-detected-mobility(44) */
	3,	/* release-due-to-ngran-generated-reason(3) */
	46,	/* release-due-to-pre-emption(46) */
	18,	/* resource-optimisation-handover(18) */
	42,	/* resources-not-available-for-the-slice(42) */
	39,	/* slice-not-supported(39) */
	2,	/* successful-handover(2) */
	17,	/* time-critical-handover(17) */
	9,	/* tngrelocoverall-expiry(9) */
	10,	/* tngrelocprep-expiry(10) */
	1,	/* txnrelocoverall-expiry(1) */
	35,	/* ue-context-transfer(35) */
	40,	/* ue-in-rrc-inactive-state-not-reachable(40) */
	43,	/* ue-max-integrity-protected-data-rate-reason(43) */
	26,	/* unknown-PDU-session-ID(26) */
	14,	/* unknown-local-UE-NGAP-ID(14) */
	12,	/* unknown-targetID(12) */
	27,	/* unkown-qos-flow-ID(27) */
	0,	/* unspecified(0) */
	38,	/* up-confidentiality-protection-not-possible(38) */
	37,	/* up-integrity-protection-not-possible(37) */
	20,	/* user-inactivity(20) */
	33	/* xn-handover-triggered(33) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_Ngap_CauseRadioNetwork_specs_1 = {
	asn_MAP_Ngap_CauseRadioNetwork_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_Ngap_CauseRadioNetwork_enum2value_1,	/* N => "tag"; sorted by N */
	48,	/* Number of elements in the maps */
	46,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_Ngap_CauseRadioNetwork_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_Ngap_CauseRadioNetwork = {
	"CauseRadioNetwork",
	"CauseRadioNetwork",
	&asn_OP_NativeEnumerated,
	asn_DEF_Ngap_CauseRadioNetwork_tags_1,
	sizeof(asn_DEF_Ngap_CauseRadioNetwork_tags_1)
		/sizeof(asn_DEF_Ngap_CauseRadioNetwork_tags_1[0]), /* 1 */
	asn_DEF_Ngap_CauseRadioNetwork_tags_1,	/* Same as above */
	sizeof(asn_DEF_Ngap_CauseRadioNetwork_tags_1)
		/sizeof(asn_DEF_Ngap_CauseRadioNetwork_tags_1[0]), /* 1 */
	{ &asn_OER_type_Ngap_CauseRadioNetwork_constr_1, &asn_PER_type_Ngap_CauseRadioNetwork_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_Ngap_CauseRadioNetwork_specs_1	/* Additional specs */
};

