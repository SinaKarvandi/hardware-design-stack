# File saved with Nlview 7.0r6  2020-01-29 bk=1.5227 VDI=41 GEI=36 GUI=JA:10.0 non-TLS-threadsafe
# 
# non-default properties - (restore without -noprops)
property attrcolor #000000
property attrfontsize 8
property autobundle 1
property backgroundcolor #ffffff
property boxcolor0 #000000
property boxcolor1 #000000
property boxcolor2 #000000
property boxinstcolor #000000
property boxpincolor #000000
property buscolor #008000
property closeenough 5
property createnetattrdsp 2048
property decorate 1
property elidetext 40
property fillcolor1 #ffffcc
property fillcolor2 #dfebf8
property fillcolor3 #f0f0f0
property gatecellname 2
property instattrmax 30
property instdrag 15
property instorder 1
property marksize 12
property maxfontsize 12
property maxzoom 5
property netcolor #19b400
property objecthighlight0 #ff00ff
property objecthighlight1 #ffff00
property objecthighlight2 #00ff00
property objecthighlight3 #0095ff
property objecthighlight4 #8000ff
property objecthighlight5 #ffc800
property objecthighlight7 #00ffff
property objecthighlight8 #ff00ff
property objecthighlight9 #ccccff
property objecthighlight10 #0ead00
property objecthighlight11 #cefc00
property objecthighlight12 #9e2dbe
property objecthighlight13 #ba6a29
property objecthighlight14 #fc0188
property objecthighlight15 #02f990
property objecthighlight16 #f1b0fb
property objecthighlight17 #fec004
property objecthighlight18 #149bff
property objecthighlight19 #eb591b
property overlapcolor #19b400
property pbuscolor #000000
property pbusnamecolor #000000
property pinattrmax 20
property pinorder 2
property pinpermute 0
property portcolor #000000
property portnamecolor #000000
property ripindexfontsize 8
property rippercolor #000000
property rubberbandcolor #000000
property rubberbandfontsize 12
property selectattr 0
property selectionappearance 2
property selectioncolor #0000ff
property sheetheight 44
property sheetwidth 68
property showmarks 1
property shownetname 0
property showpagenumbers 1
property showripindex 4
property timelimit 1
#
module new Switch_Control work:Switch_Control:NOFILE -nosplit
load symbol BUFG hdi_primitives BUF pin O output pin I input fillcolor 1
load symbol IBUF hdi_primitives BUF pin O output pin I input fillcolor 1
load symbol OBUF hdi_primitives BUF pin O output pin I input fillcolor 1
load symbol LUT1 hdi_primitives BOX pin O output.right pin I0 input.left fillcolor 1
load symbol FDRE hdi_primitives GEN pin Q output.right pin C input.clk.left pin CE input.left pin D input.left pin R input.left fillcolor 1
load port clock input -pg 1 -lvl 0 -x 0 -y 60
load port switch output -pg 1 -lvl 5 -x 750 -y 90
load inst clock_IBUF_BUFG_inst BUFG hdi_primitives -attr @cell(#000000) BUFG -pg 1 -lvl 2 -x 220 -y 60
load inst clock_IBUF_inst IBUF hdi_primitives -attr @cell(#000000) IBUF -pg 1 -lvl 1 -x 40 -y 60
load inst switch_OBUF_inst OBUF hdi_primitives -attr @cell(#000000) OBUF -pg 1 -lvl 4 -x 590 -y 90
load inst toggle_i_1 LUT1 hdi_primitives -attr @cell(#000000) LUT1 -pg 1 -lvl 2 -x 220 -y 120
load inst toggle_reg FDRE hdi_primitives -attr @cell(#000000) FDRE -pg 1 -lvl 3 -x 460 -y 90
load net <const0> -ground -pin toggle_reg R
load net <const1> -power -pin toggle_reg CE
load net clock -port clock -pin clock_IBUF_inst I
netloc clock 1 0 1 NJ 60
load net clock_IBUF -pin clock_IBUF_BUFG_inst I -pin clock_IBUF_inst O
netloc clock_IBUF 1 1 1 NJ 60
load net clock_IBUF_BUFG -pin clock_IBUF_BUFG_inst O -pin toggle_reg C
netloc clock_IBUF_BUFG 1 2 1 NJ 60
load net p_0_in -pin toggle_i_1 O -pin toggle_reg D
netloc p_0_in 1 2 1 410J 100n
load net switch -port switch -pin switch_OBUF_inst O
netloc switch 1 4 1 NJ 90
load net switch_OBUF -pin switch_OBUF_inst I -pin toggle_i_1 I0 -pin toggle_reg Q
netloc switch_OBUF 1 1 3 180 190 NJ 190 550
levelinfo -pg 1 0 40 220 460 590 750
pagesize -pg 1 -db -bbox -sgen -90 0 840 200
show
zoom 1.32318
scrollpos -107 -128
#
# initialize ictrl to current module Switch_Control work:Switch_Control:NOFILE
ictrl init topinfo |
