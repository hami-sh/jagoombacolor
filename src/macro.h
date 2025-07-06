#pragma once

	.macro global_func function
	.global \function
	.type   \function STT_FUNC
	.endm

	.macro adrl2 reg,label
	mov \reg,#\label&0x0FF00000
	add \reg,\reg,#\label&0x000FFFFF
	.endm

	.macro start_map base, register
	@GBLA _map_address_
 _map_address_ = \base
	.endm

	.macro _m_ label=0,size
	.if \label != 0
 \label = _map_address_
	.endif
 _map_address_ = _map_address_ + \size
	.endm

	.macro ldr_ reg,label
	.if \label > 4095 || \label < -4095
	ldr \reg, =\label
	add \reg, globalptr, \reg
	ldr \reg, [\reg]
	.else
	ldr \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro ldrb_ reg,label
	.if \label > 4095 || \label < -4095
	ldr \reg, =\label
	add \reg, globalptr, \reg
	ldrb \reg, [\reg]
	.else
	ldrb \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro ldrh_ reg,label
	ldrh \reg,[globalptr,#\label]
	.endm
	
	.macro str_ reg,label
	.if \label > 4095 || \label < -4095
	ldr r12, =\label
	add r12, globalptr, r12
	str \reg, [r12]
	.else
	str \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strb_ reg,label
	.if \label > 4095 || \label < -4095
	ldr r12, =\label
	add r12, globalptr, r12
	strb \reg, [r12]
	.else
	strb \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strh_ reg,label
	strh \reg,[globalptr,#\label]
	.endm



	.macro ldreq_ reg,label
	ldreq \reg,[globalptr,#\label]
	.endm
	
	.macro ldreqb_ reg,label
	ldreqb \reg,[globalptr,#\label]
	.endm
	
	.macro streq_ reg,label
	streq \reg,[globalptr,#\label]
	.endm
	
	.macro streqb_ reg,label
	streqb \reg,[globalptr,#\label]
	.endm
	



	.macro ldrne_ reg,label
	ldrne \reg,[globalptr,#\label]
	.endm
	
	.macro ldrneb_ reg,label
	ldrneb \reg,[globalptr,#\label]
	.endm
	
	.macro strne_ reg,label
	strne \reg,[globalptr,#\label]
	.endm
	
	.macro strneb_ reg,label
	strneb \reg,[globalptr,#\label]
	.endm
	


	.macro ldrhi_ reg,label
	ldrhi \reg,[globalptr,#\label]
	.endm
	
	.macro ldrhib_ reg,label
	ldrhib \reg,[globalptr,#\label]
	.endm
	
	.macro strhi_ reg,label
	strhi \reg,[globalptr,#\label]
	.endm
	
	.macro strhib_ reg,label
	strhib \reg,[globalptr,#\label]
	.endm


	.macro ldrmi_ reg,label
	.if \label > 4095 || \label < -4095
	addmi \reg, globalptr, #((\label) & 0xFFF00000)
	addmi \reg, \reg, #((\label) & 0x000FFF00)
	ldrmi \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrmi \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro ldrmib_ reg,label
	.if \label > 4095 || \label < -4095
	addmi \reg, globalptr, #((\label) & 0xFFF00000)
	addmi \reg, \reg, #((\label) & 0x000FFF00)
	ldrmib \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrmib \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strmi_ reg,label
	.if \label > 4095 || \label < -4095
	addmi r12, globalptr, #((\label) & 0xFFF00000)
	addmi r12, r12, #((\label) & 0x000FFF00)
	strmi \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strmi \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strmib_ reg,label
	.if \label > 4095 || \label < -4095
	addmi r12, globalptr, #((\label) & 0xFFF00000)
	addmi r12, r12, #((\label) & 0x000FFF00)
	strmib \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strmib \reg,[globalptr,#\label]
	.endif
	.endm

	.macro ldrpl_ reg,label
	.if \label > 4095 || \label < -4095
	addpl \reg, globalptr, #((\label) & 0xFFF00000)
	addpl \reg, \reg, #((\label) & 0x000FFF00)
	ldrpl \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrpl \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro ldrplb_ reg,label
	.if \label > 4095 || \label < -4095
	addpl \reg, globalptr, #((\label) & 0xFFF00000)
	addpl \reg, \reg, #((\label) & 0x000FFF00)
	ldrplb \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrplb \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strpl_ reg,label
	.if \label > 4095 || \label < -4095
	addpl r12, globalptr, #((\label) & 0xFFF00000)
	addpl r12, r12, #((\label) & 0x000FFF00)
	strpl \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strpl \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strplb_ reg,label
	.if \label > 4095 || \label < -4095
	addpl r12, globalptr, #((\label) & 0xFFF00000)
	addpl r12, r12, #((\label) & 0x000FFF00)
	strplb \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strplb \reg,[globalptr,#\label]
	.endif
	.endm


	.macro ldrgt_ reg,label
	.if \label > 4095 || \label < -4095
	addgt \reg, globalptr, #((\label) & 0xFFF00000)
	addgt \reg, \reg, #((\label) & 0x000FFF00)
	ldrgt \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrgt \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro ldrgtb_ reg,label
	.if \label > 4095 || \label < -4095
	addgt \reg, globalptr, #((\label) & 0xFFF00000)
	addgt \reg, \reg, #((\label) & 0x000FFF00)
	ldrgtb \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrgtb \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strgt_ reg,label
	.if \label > 4095 || \label < -4095
	addgt r12, globalptr, #((\label) & 0xFFF00000)
	addgt r12, r12, #((\label) & 0x000FFF00)
	strgt \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strgt \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strgtb_ reg,label
	.if \label > 4095 || \label < -4095
	addgt r12, globalptr, #((\label) & 0xFFF00000)
	addgt r12, r12, #((\label) & 0x000FFF00)
	strgtb \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strgtb \reg,[globalptr,#\label]
	.endif
	.endm


	.macro ldrge_ reg,label
	.if \label > 4095 || \label < -4095
	addge \reg, globalptr, #((\label) & 0xFFF00000)
	addge \reg, \reg, #((\label) & 0x000FFF00)
	ldrge \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrge \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro ldrgeb_ reg,label
	.if \label > 4095 || \label < -4095
	addge \reg, globalptr, #((\label) & 0xFFF00000)
	addge \reg, \reg, #((\label) & 0x000FFF00)
	ldrgeb \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrgeb \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strge_ reg,label
	.if \label > 4095 || \label < -4095
	addge r12, globalptr, #((\label) & 0xFFF00000)
	addge r12, r12, #((\label) & 0x000FFF00)
	strge \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strge \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strgeb_ reg,label
	.if \label > 4095 || \label < -4095
	addge r12, globalptr, #((\label) & 0xFFF00000)
	addge r12, r12, #((\label) & 0x000FFF00)
	strgeb \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strgeb \reg,[globalptr,#\label]
	.endif
	.endm


	.macro ldrlt_ reg,label
	ldrlt \reg,[globalptr,#\label]
	.endm
	
	.macro ldrltb_ reg,label
	ldrltb \reg,[globalptr,#\label]
	.endm
	
	.macro strlt_ reg,label
	strlt \reg,[globalptr,#\label]
	.endm
	
	.macro strltb_ reg,label
	strltb \reg,[globalptr,#\label]
	.endm


	.macro ldrle_ reg,label
	.if \label > 4095 || \label < -4095
	addle \reg, globalptr, #((\label) & 0xFFF00000)
	addle \reg, \reg, #((\label) & 0x000FFF00)
	ldrle \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrle \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro ldrleb_ reg,label
	.if \label > 4095 || \label < -4095
	addle \reg, globalptr, #((\label) & 0xFFF00000)
	addle \reg, \reg, #((\label) & 0x000FFF00)
	ldrleb \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrleb \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strle_ reg,label
	.if \label > 4095 || \label < -4095
	addle r12, globalptr, #((\label) & 0xFFF00000)
	addle r12, r12, #((\label) & 0x000FFF00)
	strle \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strle \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strleb_ reg,label
	.if \label > 4095 || \label < -4095
	addle r12, globalptr, #((\label) & 0xFFF00000)
	addle r12, r12, #((\label) & 0x000FFF00)
	strleb \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strleb \reg,[globalptr,#\label]
	.endif
	.endm


	.macro ldrlo_ reg,label
	.if \label > 4095 || \label < -4095
	addlo \reg, globalptr, #((\label) & 0xFFF00000)
	addlo \reg, \reg, #((\label) & 0x000FFF00)
	ldrlo \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrlo \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro ldrlob_ reg,label
	.if \label > 4095 || \label < -4095
	addlo \reg, globalptr, #((\label) & 0xFFF00000)
	addlo \reg, \reg, #((\label) & 0x000FFF00)
	ldrlob \reg, [\reg, #((\label) & 0x000000FF)]
	.else
	ldrlob \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strlo_ reg,label
	.if \label > 4095 || \label < -4095
	addlo r12, globalptr, #((\label) & 0xFFF00000)
	addlo r12, r12, #((\label) & 0x000FFF00)
	strlo \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strlo \reg,[globalptr,#\label]
	.endif
	.endm
	
	.macro strlob_ reg,label
	.if \label > 4095 || \label < -4095
	addlo r12, globalptr, #((\label) & 0xFFF00000)
	addlo r12, r12, #((\label) & 0x000FFF00)
	strlob \reg, [r12, #((\label) & 0x000000FF)]
	.else
	strlob \reg,[globalptr,#\label]
	.endif
	.endm
	

	.macro adr_ reg,label
	.if \label > 4095 || \label < -4095
	adrl_ \reg, \label
	.else
	add \reg,globalptr,#\label
	.endif
	.endm
	
	.macro adrl_ reg,label
	.if \label&0x80000000
	sub \reg,globalptr,#((-(\label)) & 0xFF00FF00)
	sub \reg,\reg,#((-(\label)) & 0x000000FF)
	.else
	add \reg,globalptr,#((\label) & 0xFF00FF00)
	add \reg,\reg,#((\label) & 0x000000FF)
	.endif
	.endm

 .if VERSION_IN_ROM
	.macro bl_long label
	mov lr,pc
	ldr pc,=\label
	.endm

	.macro bleq_long label
	moveq lr,pc
	ldreq pc,=\label
	.endm

	.macro bllo_long label
	movlo lr,pc
	ldrlo pc,=\label
	.endm

	.macro blhi_long label
	movhi lr,pc
	ldrhi pc,=\label
	.endm

	.macro bllt_long label
	movlt lr,pc
	ldrlt pc,=\label
	.endm

	.macro blgt_long label
	movgt lr,pc
	ldrgt pc,=\label
	.endm

	.macro blle_long label
	movle lr,pc
	ldrle pc,=\label
	.endm

	.macro blge_long label
	movge lr,pc
	ldrge pc,=\label
	.endm

	.macro blne_long label
	movne lr,pc
	ldrne pc,=\label
	.endm

	.macro blcc_long label
	movcc lr,pc
	ldrcc pc,=\label
	.endm

	.macro blpl_long label
	movpl lr,pc
	ldrpl pc,=\label
	.endm

	.macro blx_long label
	add lr,pc,#4
	ldr r12,=\label
	bx r12
	.endm

	.macro blxeq_long label
	addeq lr,pc,#4
	ldreq r12,=\label
	bxeq r12
	.endm

	.macro blxlo_long label
	addlo lr,pc,#4
	ldrlo r12,=\label
	bxlo r12
	.endm

	.macro blxhi_long label
	addhi lr,pc,#4
	ldrhi r12,=\label
	bxhi r12
	.endm

	.macro blxlt_long label
	addlt lr,pc,#4
	ldrlt r12,=\label
	bxlt r12
	.endm

	.macro blxgt_long label
	addgt lr,pc,#4
	ldrgt r12,=\label
	bxgt r12
	.endm

	.macro blxne_long label
	addne lr,pc,#4
	ldrne r12,=\label
	bxne r12
	.endm

	.macro blxcc_long label
	addcc lr,pc,#4
	ldrcc r12,=\label
	bxcc r12
	.endm

	.macro blxpl_long label
	addpl lr,pc,#4
	ldrpl r12,=\label
	bxpl r12
	.endm

	.macro blxmi_long label
	addmi lr,pc,#4
	ldrmi r12,=\label
	bxmi r12
	.endm

	.macro b_long label
	ldr pc,=\label
	.endm

	.macro bcc_long label
	ldrcc pc,=\label
	.endm

	.macro bhs_long label
	ldrhs pc,=\label
	.endm

	.macro beq_long label
	ldreq pc,=\label
	.endm

	.macro bne_long label
	ldrne pc,=\label
	.endm

	.macro blo_long label
	ldrlo pc,=\label
	.endm

	.macro bhi_long label
	ldrhi pc,=\label
	.endm

	.macro bgt_long label
	ldrgt pc,=\label
	.endm

	.macro blt_long label
	ldrlt pc,=\label
	.endm

	.macro bge_long label
	ldrge pc,=\label
	.endm

	.macro ble_long label
	ldrle pc,=\label
	.endm

	.macro bcs_long label
	ldrcs pc,=\label
	.endm

	.macro bmi_long label
	ldrmi pc,=\label
	.endm

	.macro bpl_long label
	ldrpl pc,=\label
	.endm

	.else

	.macro blx_long label
	add lr,pc,#4
	ldr r12,=\label
	bx r12
	.endm

	.macro blxeq_long label
	addeq lr,pc,#4
	ldreq r12,=\label
	bxeq r12
	.endm

	.macro blxlo_long label
	addlo lr,pc,#4
	ldrlo r12,=\label
	bxlo r12
	.endm

	.macro blxhi_long label
	addhi lr,pc,#4
	ldrhi r12,=\label
	bxhi r12
	.endm

	.macro blxlt_long label
	addlt lr,pc,#4
	ldrlt r12,=\label
	bxlt r12
	.endm

	.macro blxgt_long label
	addgt lr,pc,#4
	ldrgt r12,=\label
	bxgt r12
	.endm

	.macro blxne_long label
	addne lr,pc,#4
	ldrne r12,=\label
	bxne r12
	.endm

	.macro blxcc_long label
	addcc lr,pc,#4
	ldrcc r12,=\label
	bxcc r12
	.endm

	.macro blxpl_long label
	addpl lr,pc,#4
	ldrpl r12,=\label
	bxpl r12
	.endm

	.macro blxmi_long label
	addmi lr,pc,#4
	ldrmi r12,=\label
	bxmi r12
	.endm

	.macro bl_long label
	bl \label
	.endm

	.macro bleq_long label
	bleq \label
	.endm

	.macro bllo_long label
	bllo \label
	.endm

	.macro blhi_long label
	blhi \label
	.endm

	.macro bllt_long label
	bllt \label
	.endm

	.macro blgt_long label
	blgt \label
	.endm
	
	.macro blle_long label
	blle \label
	.endm

	.macro blge_long label
	blge \label
	.endm

	.macro blne_long label
	blne \label
	.endm

	.macro blcc_long label
	blcc \label
	.endm

	.macro blpl_long label
	blpl \label
	.endm

	.macro b_long label
	b \label
	.endm

	.macro bcc_long label
	bcc \label
	.endm

	.macro bhs_long label
	bhs \label
	.endm

	.macro beq_long label
	beq \label
	.endm

	.macro bne_long label
	bne \label
	.endm

	.macro blo_long label
	blo \label
	.endm

	.macro bhi_long label
	bhi \label
	.endm

	.macro bgt_long label
	bgt \label
	.endm

	.macro blt_long label
	blt \label
	.endm

	.macro bge_long label
	bge \label
	.endm

	.macro ble_long label
	ble \label
	.endm

	.macro bcs_long label
	bcs \label
	.endm

	.macro bmi_long label
	bmi \label
	.endm

	.macro bpl_long label
	bpl \label
	.endm
 .endif

	@.end

