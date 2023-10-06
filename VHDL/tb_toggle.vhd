library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Switch_Control_tb is
end Switch_Control_tb;

architecture testbench of Switch_Control_tb is
    -- Signals for testbench
    signal clock_tb  : STD_LOGIC := '0'; -- Testbench clock signal
    signal switch_tb : STD_LOGIC;        -- Testbench switch signal

begin
    -- Instantiate the Switch_Control DUT
    DUT: entity work.Switch_Control
        port map (
            clock   => clock_tb,
            switch  => switch_tb
        );

    -- Clock generation process (generates a clock signal)
    process
    begin
        while true loop
            clock_tb <= not clock_tb; -- Toggle the clock
            wait for 5 ns;            -- Clock period (adjust as needed)
        end loop;
    end process;

end testbench;