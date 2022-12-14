<CsoundSynthesizer>
<CsOptions>
-odac
</CsOptions>
<CsInstruments>
; this is a comment
; this is the orchestra file (.orc):
sr = 44100 ; sampling rate
ksmps = 10 ; k-rate
kr = 4410 ; k-rate the other way
nchnls = 1 ; mono

; instrument #1
instr 1
	a1 oscil 10000, 200, 1
	out a1
endin

</CsInstruments>
<CsScore>
; this is the score file (.sco):

; f is for function table
; args are:
; tablenumber, actiontime, size, genvalue, args
; GEN10 fils a table with harmonic values 
; where all the arguments are harmonic strengths
f 1 0 8192 10 1 0 0.5 0 0.3 0 0.2
; i is for instrument (plays a note)
; args are:
; instrumentnumber, actiontime, duration, args
i 1 0 2
e
</CsScore>
</CsoundSynthesizer>
<bsbPanel>
 <label>Widgets</label>
 <objectName/>
 <x>100</x>
 <y>100</y>
 <width>320</width>
 <height>240</height>
 <visible>true</visible>
 <uuid/>
 <bgcolor mode="nobackground">
  <r>255</r>
  <g>255</g>
  <b>255</b>
 </bgcolor>
</bsbPanel>
<bsbPresets>
</bsbPresets>
