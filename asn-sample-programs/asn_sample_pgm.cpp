#include <stdbool.h>
#include <string.h>
#include <bstrlib.h>
#include "common_ngap_asn.h"

typedef unsigned char     uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned int      uint32_t;
typedef unsigned long int uint64_t;


int ngap_asn_decode_pdu(Ngap_NGAP_PDU_t* pdu, const_bstring const raw) {
  asn_dec_rval_t dec_ret;
  dec_ret = aper_decode(NULL, &asn_DEF_Ngap_NGAP_PDU, (void**)&pdu, bdata(raw),
                        blength(raw), 0, 0);

  if (dec_ret.code != RC_OK) {
    return -1;
  }
  return 0;
}

int ngap_asn_encode_pdu(Ngap_NGAP_PDU_t* pdu,
                        uint8_t** buffer,
                        uint32_t* length) {
  asn_encode_to_new_buffer_result_t res = {NULL, {0, NULL, NULL}};
  memset(&res, 0, sizeof(res));
  res = asn_encode_to_new_buffer(NULL, ATS_ALIGNED_CANONICAL_PER,
                                 &asn_DEF_Ngap_NGAP_PDU, pdu);
  *buffer = (uint8_t*)res.buffer;
  *length = res.result.encoded;

  return (0);
}

bool generate_ngap_reset_partial_request(bstring& stream) {
  uint8_t* buffer_p = NULL;
  uint32_t length = 0;
  Ngap_NGAP_PDU_t pdu;
  Ngap_NGReset_t* out;

  memset(&pdu, 0, sizeof(pdu));

  pdu.present = Ngap_NGAP_PDU_PR_initiatingMessage;
  pdu.choice.initiatingMessage.procedureCode =
      Ngap_ProcedureCode_id_NGReset;
  pdu.choice.initiatingMessage.criticality = Ngap_Criticality_reject;
  pdu.choice.initiatingMessage.value.present =
      Ngap_InitiatingMessage__value_PR_NGReset;

  out =
  &pdu.choice.initiatingMessage.value.choice.NGReset;

  Ngap_NGResetIEs_t* ie = NULL;

  ie = (Ngap_NGResetIEs_t*)calloc(1, sizeof(Ngap_NGResetIEs_t));
  ie->id = Ngap_ProtocolIE_ID_id_Cause;
  ie->criticality = Ngap_Criticality_ignore;
  ie->value.present = Ngap_NGResetIEs__value_PR_Cause;
  ie->value.choice.Cause.present =  Ngap_Cause_PR_radioNetwork;
  ie->value.choice.Cause.choice.radioNetwork =  Ngap_CauseRadioNetwork_unspecified;
  ASN_SEQUENCE_ADD(&out->protocolIEs.list, ie);

  // Reset IE
  ie = (Ngap_NGResetIEs_t*)calloc(1, sizeof(Ngap_NGResetIEs_t));
  ie->id = Ngap_ProtocolIE_ID_id_ResetType;
  ie->criticality = Ngap_Criticality_reject;
  ie->value.present = Ngap_NGResetIEs__value_PR_ResetType;
  ie->value.choice.ResetType.present = Ngap_ResetType_PR_partOfNG_Interface;

  Ngap_UE_associatedLogicalNG_connectionItem *ie_logical_ng_connection_item =
    (Ngap_UE_associatedLogicalNG_connectionItem *) calloc(
    1, sizeof(Ngap_UE_associatedLogicalNG_connectionItem));

  uint64_t amf_ue_id = 1;
  uint64_t ran_ue_id = 5948;

  ie_logical_ng_connection_item->aMF_UE_NGAP_ID = (Ngap_AMF_UE_NGAP_ID_t *) calloc(1, sizeof(Ngap_AMF_UE_NGAP_ID_t));
  asn_uint642INTEGER(ie_logical_ng_connection_item->aMF_UE_NGAP_ID, amf_ue_id);

  ie_logical_ng_connection_item->rAN_UE_NGAP_ID = (Ngap_RAN_UE_NGAP_ID_t *) calloc(1, sizeof(Ngap_RAN_UE_NGAP_ID_t));
  *ie_logical_ng_connection_item->rAN_UE_NGAP_ID = ran_ue_id;

  ASN_SEQUENCE_ADD(&(ie->value.choice.ResetType.choice.partOfNG_Interface.list),
                   ie_logical_ng_connection_item);

  ASN_SEQUENCE_ADD(&out->protocolIEs.list, ie);

  if (ngap_asn_encode_pdu(&pdu, &buffer_p, &length) < 0) {
    return (false);
  }

  stream = blk2bstr(buffer_p, length);
  free(buffer_p);

  printf("\n ---------\n");
  for (int i=0; i<length; i++) {
    printf(" %x ", buffer_p[i]);
  }

  return (true);
}

int main () {
  bstring stream;
  Ngap_NGAP_PDU_t decode_pdu;
  bool decode_ops = false;
  bool output = false;

  output = generate_ngap_reset_partial_request(stream);
  if (output == true) {
    memset(&decode_pdu, 0, sizeof(decode_pdu));
    decode_ops = ngap_asn_decode_pdu(&decode_pdu, stream);
    if (decode_ops != 0) {
       printf("\n %% Failed Badly in decoding \n");
    } else {
       printf("\n Success in decoding \n");
       asn_fprint(stderr, &asn_DEF_Ngap_NGAP_PDU, (void*) &decode_pdu);
    }
  }
  
  bdestroy(stream);

  ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_Ngap_NGAP_PDU, &decode_pdu);

  return (0);
}
