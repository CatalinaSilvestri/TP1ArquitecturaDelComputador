#ifndef __MIS_SALTOS__
#define __MIS_SALTOS__

  typedef struct _salvarEstado{
    long int rbx, rpb, rsp, r10, r11, r12, r13, r14, r15;
    int estado_salto;
  } salvarEstado;

  typedef salvarEstado miBuf_jump[1];

  int set_jump2(miBuf_jump buf);

  void long_jump2(miBuf_jump buf, int);

#endif /* __MIS_SALTOS__ */