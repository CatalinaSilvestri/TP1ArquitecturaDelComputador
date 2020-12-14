        .text
        .arm
        .global campesino_ruso

campesino_ruso:
  @r0 = i
  @r1 = j
  @r2 = res
  MOV r2, #0
  while:
    ADD r3, r1, #1
    CMP r1, #2

    BLO salida

    TST r1, #1

    ADDNE r2, r2, r0
    SUBNE r1, r1, #1

    MOVEQ r0, r0, LSL #1
    MOVEQ r1, r1, LSR #1
    B while

  salida:
  ADD r0, r0, r2  
  bx lr
