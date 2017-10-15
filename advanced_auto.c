// Ragnarok Online Mobile: Advanced Auto
// Hanya dirilis untuk Discord Server ROM Indonesia
// Created by Yuuki
// Version 1.0.0
// Hanya dapat digunakan pada device ber-resolusi 1280x720
// Harap matikan Floating Text pada Guild Chat dan Party Chat!!

// -------------------------------- Change Log ------------------------------ //
// -- Version 1.0.0 --
// • Initial Release
// -- Version 1.0.1
// • Fixed Auto Mode Bug on Normal Monster
// • Add function check monster before start recovery mode
// -------------------------------------------------------------------------- //

// ------------------------------ Configuration ----------------------------- //
// -- Auto Detection --
// Secara default mode ini sudah aktif. Cara melakukan auto mode adalah dengan-
// memilih target sampai keluar target avatar disamping character avatar atau-
// pet avatar. Setelah avatar target keluar, jalankan macro dan macro akan-
// secara otomatis mengunci target. Setelah itu jalankan auto-hunt dengan-
// target yang telah dipilih sebelumnya sebagai target macro.
// On: 1
// Off: 0 (manual mode)
// Default: 1
Var #auto_mode 1

// -- Target Monster Color (Manual Mode) --
// Terdapat 3 value yang digunakan untuk deteksi warna monster (RGB).
// Ini digunakan agar macro dapat mendeteksi monster disekitar character.
// Hydra: -86 -22 -103
// Dark Priest: -? -? -?
// Minorous: -? -? -?
Var #monster_r -86
Var #monster_g -22
Var #monster_b -103

// -- Hydra★ Mode --
// Mode ini hanya digunakan untuk membedakan antara monster hydra★ dan monster
// hydra biasa.
// Beri nilai 0 jika tidak melakukan auto hydra★.
// Default: 0
Var #hydra_mode_active 0
// RGB Value
// Hydra★: -1 -1 -1
Var #monster_r2 -1
Var #monster_g2 -1
Var #monster_b2 -1

// -- Delay After Target Detected --
// Set delay waktu tunggu macro setelah mendeteksi target monster.
// Setelah delay selesai macro akan melakukan perulangan algoritma.
// Nilai durasi adalah n*1000 (n adalah durasi dalam detik).
// Defailt: 10000 (10 detik)
Var #delay 10000

// -- Recovery Mode --
// Recovery mode adalah konfigurasi yang digunakan untuk pemilihan mode-
// recovery yang digunakan saat HP/SP melampaui batas threshold.
// Sit Mode: 0
// Play Dead: 1
// Default: 0 (Sit Mode)
Var #recov_mode 0

// Recovery duration adalah durasi saat Sit ataupun Play Dead.
// Durasi Play Dead saat "Sleep State" adalah detik ke-30, sehingga untuk-
// Play Dead durasi maksimal adalah 28 detik.
// Nilai durasi adalah n*1000 (n adalah durasi dalam detik).
// Default: 30000 (30 detik)
Var #recov_duration 30000

// -- Peco Mode --
// Jika menggunakan peco, peco akan hilang saat resting menggunakan "Sit Mode".
// Letakkan peco pada item shortcut box nomer 1 dan aktifkan mode ini-
// sehingga saat sebelum berjalan kembali dari "Sit Mode", akan mengaktifkan-
// peco riding.
// Default: 0
Var #peco_mode 0

// -- HP Threshold --
// HP threshold adalah konfigurasi mode pendeteksian kapan character harus-
// melakukan Play Dead atau Rest (sit).
// Contoh saat diberi threshold sebesar 70%, maka saat HP dibawah 70% macro akan-
// melakukan Recovery Mode (Sit/Playdead).
// HP 70%: 1
// HP 50%: 2
// HP 30%: 3
// Default: 2
Var #hp_threshold 2

// -- SP Threshold --
// SP threshold adalah konfigurasi mode pendeteksian kapan character harus-
// melakukan Play Dead atau Rest (sit).
// Contoh saat diberi threshold sebesar 50%, maka saat SP dibawah 50% macro akan-
// melakukan Recovery Mode (Sit/Playdead).
// SP 70%: 1
// SP 50%: 2
// SP 30%: 3
// Default: 3
Var #sp_threshold 3

// -- Teleport Mode --
// Metode yang digunakan untuk teleport.
// Fly Wing: 0
// Teleport (skill): 1
// Defaul: 0
Var #teleport_mode 0

// -- Fly Wing Item Shortcut Box Number Config --
// Letak item "Fly Wing" di item shortcut box.
// Nilai antara 1 sampai dengan 5, dihitung mulai dari shortcut box paling kiri.
Var #fw_item 5

// -- Teleport Skill Shortcut Box Number Config --
// Letak skill "Teleport" di skill shortcut box.
// Nilai antara 1 sampai dengan 6, dihitung mulai dari shortcut box paling kiri.
Var #tele_skill 5

// -- Play Dead Skill Shortcut Box Number Config --
// Letak skill "Play Dead" di skill shortcut box.
// Nilai antara 1 sampai dengan 6, dihitung mulai dari shortcut box paling kiri.
Var #pd_skill 6

// -------------------------------------------------------------------------- //
// --------------- PLEASE DO NOT EDIT THE CODE FROM THIS LINE --------------- //
// ------------------- UNLESS YOU KNOW WHAT ARE YOU DOING ------------------- //
// -------------------------------------------------------------------------- //

// -- Item shortcut box coordinates (x,y) --
// Item 1: 745 554
// Item 2: 842 554
// Item 3: 939 554
// Item 4: 1033 554
// Item 5: 1131 554

// -- Skill shortcut box coordinates (x, y) --
// Skill 1 : 745 651
// Skill 2 : 843 651
// Skill 3 : 938 651
// Skill 4 : 1031 651
// Skill 5 : 1131 651
// Skill 6 : 1228 651

// -- HP bar coordinates (x,y) --
// 70%: 155 122
// 50%: 94 122
// 30%: 70 122

// -- SP bar coordinates (x,y) --
// 70%: 155 132
// 50%: 94 132
// 30%: 70 132

// -- Colors (RGB) --
// HP (Green): 136 211 36
// SP (Blue): -142 -109 -24
// 70% HP Threshold: 97 99 102
// 50% HP Threshold: 98 100 102
// 30% HP Threshold: 97 99 102
// 70% SP Threshold: 96 98 101
// 50% SP Threshold: 97 99 101
// 30% SP Threshold: 96 99 101
// Monster X Button: 221 255 9

// -- Variables --
// Auto Mode Initialize
Var #init 0

// Item shortcut box coordinates
Var #x1 745
Var #x2 842
Var #x3 939
Var #x4 1033
Var #x5 1131
Var #x 0
Var #y 554

// Skill shortcut box coordinates
Var #sx1 745
Var #sx2 843
Var #sx3 938
Var #sx4 1031
Var #sx5 1131
Var #sx6 1228
Var #sx 0
Var #sy 651

// Playdead skill shortcut box coordinates
Var #pdx1 745
Var #pdx2 843
Var #pdx3 938
Var #pdx4 1031
Var #pdx5 1131
Var #pdx6 1228
Var #pdx 0
Var #pdy 651

// Toast Delay Value
Var #tdelay 0
Var #trecov 0
Calc #tdelay #delay / 1000

// Monster target coordinates
Var #mx 282
Var #my 163

// HP Threshold
Var #min_hpx 0
Var #hpy 0

// HP Threshold
Var #min_spx 0
Var #spy 0

// HP Bar Color
Var #hp_red 0
Var #hp_green 0
Var #hp_blue 0

// SP Bar Color
Var #sp_red 0
Var #sp_green 0
Var #sp_blue 0

// RGB
Var #red 0
Var #green 0
Var #blue 0

// Function Call
// 0 = None
// 1 = Playdead Function
// 2 = Sit Down Function
Var #caller 0

// Timer Variable
Var #timer 0
Var #t_timer 0
Set #timer #recov_duration

// Configuring item shortcut box
elseif #fw_item == 1
	Set #x #x1
elseif #fw_item == 2
	Set #x #x2
elseif #fw_item == 3
	Set #x #x3
elseif #fw_item == 4
	Set #x #x4
elseif #fw_item == 5
	Set #x #x5
endif

// Configuring teleport skill shortcut box
if #tele_skill == 1
	Set #sx #sx1
elseif #tele_skill == 2
	Set #sx #sx2
elseif #tele_skill == 3
	Set #sx #sx3
elseif #tele_skill == 4
	Set #sx #sx4
elseif #tele_skill == 5
	Set #sx #sx5
elseif #tele_skill == 6
	Set #sx #sx6
endif

// Configuring play dead skill shortcut box
if #pd_skill == 1
	Set #pdx #pdx1
elseif #pd_skill == 2
	Set #pdx #pdx2
elseif #pd_skill == 3
	Set #pdx #pdx3
elseif #pd_skill == 4
	Set #pdx #pdx4
elseif #pd_skill == 5
	Set #pdx #pdx5
elseif #pd_skill == 6
	Set #pdx #pdx6
endif

// Configuring hp threshold
if #hp_threshold == 1
	Set #min_hpx 155
	Set #hpy 122
	Set #hp_red 97
	Set #hp_green 99
	Set #hp_blue 102
endif
if #hp_threshold == 2
	Set #min_hpx 94
	Set #hpy 122
	Set #hp_red 98
	Set #hp_green 100
	Set #hp_blue 102
endif
if #hp_threshold == 3
	Set #min_hpx 70
	Set #hpy 122
	Set #hp_red 97
	Set #hp_green 99
	Set #hp_blue 102
endif

// Configuring sp threshold
if #sp_threshold == 1
	Set #min_spx 155
	Set #spy 132
	Set #sp_red 96
	Set #sp_green 98
	Set #sp_blue 101
endif
if #sp_threshold == 2
	Set #min_spx 94
	Set #spy 132
	Set #sp_red 97
	Set #sp_green 99
	Set #sp_blue 101
endif
if #sp_threshold == 3
	Set #min_spx 70
	Set #spy 132
	Set #sp_red 96
	Set #sp_green 99
	Set #sp_blue 101
endif

// -- Macro start here --
:start

if #auto_mode == 1 and #init == 0
	getRGB #red #green #blue 309 139
endif

if #red == 221 and #green == 255 and #blue == 9 and #auto_mode == 1 and #init == 0
	getRGB #monster_r #monster_g #monster_b #mx #my
	Set #init 1
	Toast Target Found! Macro Activated!
elseif #auto_mode == 1 and #init == 0
	Toast Could not find target, retrying in 10 secs.
	sleep 10000
	goto :start
endif

:check_hp
getRGB #red #green #blue #min_hpx #hpy
if #red == #hp_red and #green == #hp_green and #blue == #hp_blue and #recov_mode == 0
	goto :resting
endif
if #red == #hp_red and #green == #hp_green and #blue == #hp_blue and #recov_mode == 1
	goto :play_dead
endif

:check_sp
getRGB #red #green #blue #min_spx #spy
if #red == #sp_red and #green == #sp_green and #blue == #sp_blue and #recov_mode == 0
	goto :resting
endif
if #red == #sp_red and #green == #sp_green and #blue == #sp_blue and #recov_mode == 1
	goto :play_dead
endif

if #hydra_mode_active == 0
	goto :check_monster
endif

:check_monster_hydra
getRGB #red #green #blue #mx #my
if #red == #monster_r and #green == #monster_g and #blue == #monster_b
	getRGB #red #green #blue 300 178
	if #red == #monster_r2 and #green == #monster_g2 and #blue == #monster_b2
		Toast Target found! Wait for #tdelay secs...
		sleep #delay
		goto :start
		else
		goto :fly
	endif
endif

:check_monster
getRGB #red #green #blue #mx #my
if #red == #monster_r and #green == #monster_g and #blue == #monster_b
	Toast Target found! Wait for #tdelay secs...
	sleep #delay
	goto :start
endif

:fly
if #teleport_mode == 0
	touchDown 0 #x #y
	touchUp 0
	Fly Wing Used!
	sleep 5000
else
	touchDown 0 #sx #sy
	touchUp 0
	Teleporting!
	sleep 7000
endif

if #caller == 1
	goto :play_dead2
endif

if #caller == 2
	goto :resting2
endif

goto :check_hp

:play_dead
Toast Recover mode start!
Set #caller 1
goto :fly
:play_dead2
getRGB #red #green #blue 309 139
if #red == 221 and #green == 255 and #blue == 9
	Toast You are being targeted!
	Calc #timer #timer + 3000
	goto :fly
endif
touchDown 0 #pdx #pdy
touchUp 0
Toast Play Dead...
:play_dead3
Calc #t_timer #timer / 1000
Toast Recover Duration: #t_timer secs
sleep 5000
Calc #timer #timer - 5000
getRGB #red #green #blue 309 139
if #red == 221 and #green == 255 and #blue == 9
	Toast You are being targeted!
	Calc #timer #timer + 3000
	goto :fly
endif
if #timer <= 0
	Set #caller 0
	Set #timer #recov_duration
	goto :fly
endif
goto :play_dead3

:resting
Toast Recover mode start!
Set #caller 2
goto :fly
:resting2
getRGB #red #green #blue 309 139
if #red == 221 and #green == 255 and #blue == 9
	Toast You are being targeted!
	Calc #timer #timer + 3000
	goto :fly
endif
touchDown 0 63 571
touchUp 0
sleep 700
touchDown 0 63 571
touchUp 0
sleep 1000
touchDown 0 1188 464
touchUp 0
sleep 1000
if #peco_mode == 1
	touchDown 0 745 554
	touchUp 0
endif
Toast Resting...
:resting3
Calc #t_timer #timer / 1000
Toast Recover Duration: #t_timer secs
sleep 5000
Calc #timer #timer - 5000
getRGB #red #green #blue 309 139
if #red == 221 and #green == 255 and #blue == 9
	Toast You are being targeted!
	Calc #timer #timer + 3000
	goto :fly
endif
if #timer <= 0
	Set #caller 0
	Set #timer #recov_duration
	goto :fly
endif
goto :resting3

:end
