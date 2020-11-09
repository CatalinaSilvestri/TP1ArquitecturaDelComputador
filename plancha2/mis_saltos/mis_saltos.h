#ifndef __MIS_SALTOS__
#define __MIS_SALTOS__

  typedef struct _salvarEstado{
    long int rbx, rbp, rsp, r10, r11, r12, r13, r14, r15;
    long int estado_salto; // para que sirve?
  } salvarEstado;

  typedef salvarEstado miBuf_jump[1];

  int setjmp2(miBuf_jump buf);

  void longjmp2(miBuf_jump buf, int retorno);

#endif /* __MIS_SALTOS__ */