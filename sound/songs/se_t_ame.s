	.include "MPlayDef.s"

	.equ	se_t_ame_grp, voicegroup_8451F90
	.equ	se_t_ame_pri, 2
	.equ	se_t_ame_rev, reverb_set+50
	.equ	se_t_ame_mvl, 127
	.equ	se_t_ame_key, 0
	.equ	se_t_ame_tbs, 1
	.equ	se_t_ame_exg, 0
	.equ	se_t_ame_cmp, 1

	.section .rodata
	.global	se_t_ame
	.align	2

@********************** Track  1 **********************@

se_t_ame_1:
	.byte	KEYSH , se_t_ame_key+0
	.byte	TEMPO , 220*se_t_ame_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 15*se_t_ame_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Gn3 , v060
	.byte	W03
	.byte		VOL   , 27*se_t_ame_mvl/mxv
	.byte	W03
	.byte		        39*se_t_ame_mvl/mxv
	.byte	W03
	.byte		        44*se_t_ame_mvl/mxv
	.byte	W03
	.byte		        52*se_t_ame_mvl/mxv
	.byte	W03
	.byte		        59*se_t_ame_mvl/mxv
	.byte	W03
	.byte		        68*se_t_ame_mvl/mxv
	.byte	W03
	.byte		        80*se_t_ame_mvl/mxv
	.byte	W03
se_t_ame_1_B1:
	.byte		N60   , Gn3 , v060
	.byte	W24
	.byte	W24
	.byte	W12
	.byte	GOTO
	 .word	se_t_ame_1_B1
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_t_ame:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_t_ame_pri	@ Priority
	.byte	se_t_ame_rev	@ Reverb.

	.word	se_t_ame_grp

	.word	se_t_ame_1

	.end
