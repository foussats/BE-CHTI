	thumb
	area  moncode, code, readonly
	extern TabSig
	extern TabSin
	extern TabCos
	export reel
;
reel proc
;somme de i allant de 0 a N-1, de xi * cos(ik2pi/N)
;3 args entree: valeur de k, valeur deb tab cos/sin, val deb tab signal
; r0 contient signal, r1 contient k, r2 contient tab cos sin
	push {lr}
; r12 correspond a l'iterateur boucle for 
; r3 contient res
	mov r12,#0
N equ 8 
	push {r4}
	push {r5}
boucle	
	mul r3,r12,r1
; i*k dans r3
	and r3, #N
;modulo avec N dans r3 (-> index du cos)
	ldr r4, =TabCos
	ldrsh r3, [r4,r3, lsl #1]
	ldrsh  r5, [r0, r12, lsl #1]
	mul r3, r5
	add r12,#1
	cmp r12, #64
	blt boucle
	pop {r5}
	pop {r4}
	pop	{pc}
	endp

	end
		

		