-- Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2022.2 (win64) Build 3671981 Fri Oct 14 05:00:03 MDT 2022
-- Date        : Thu Oct  5 21:14:02 2023
-- Host        : DESKTOP-J3QO9T8 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -mode funcsim VHDL_Netlist_Name.vhd
-- Design      : Switch_Control
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity Switch_Control is
  port (
    clock : in STD_LOGIC;
    switch : out STD_LOGIC
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of Switch_Control : entity is true;
end Switch_Control;

architecture STRUCTURE of Switch_Control is
  signal clock_IBUF : STD_LOGIC;
  signal clock_IBUF_BUFG : STD_LOGIC;
  signal p_0_in : STD_LOGIC;
  signal switch_OBUF : STD_LOGIC;
begin
clock_IBUF_BUFG_inst: unisim.vcomponents.BUFG
     port map (
      I => clock_IBUF,
      O => clock_IBUF_BUFG
    );
clock_IBUF_inst: unisim.vcomponents.IBUF
    generic map(
      CCIO_EN => "TRUE"
    )
        port map (
      I => clock,
      O => clock_IBUF
    );
switch_OBUF_inst: unisim.vcomponents.OBUF
     port map (
      I => switch_OBUF,
      O => switch
    );
toggle_i_1: unisim.vcomponents.LUT1
    generic map(
      INIT => X"1"
    )
        port map (
      I0 => switch_OBUF,
      O => p_0_in
    );
toggle_reg: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clock_IBUF_BUFG,
      CE => '1',
      D => p_0_in,
      Q => switch_OBUF,
      R => '0'
    );
end STRUCTURE;
