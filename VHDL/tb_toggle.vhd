library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Switch_Control_tb is
end Switch_Control_tb;

architecture testbench of Switch_Control_tb is
    -- Constants for simulation parameters
    constant CLOCK_PERIOD : time := 10 ns; -- Clock period (10 ns for example)

    -- Signals for testbench
    signal clock_tb    : STD_LOGIC := '0'; -- Testbench clock signal
    signal switch_tb   : STD_LOGIC;        -- Testbench switch signal
    signal stop_tb     : BOOLEAN := FALSE; -- Stop simulation signal

begin
    -- Instantiate the Switch_Control DUT
    DUT: entity work.Switch_Control
        port map (
            clock   => clock_tb,
            switch  => switch_tb
        );

    -- Clock process (generates clock signal)
    process
    begin
        while not stop_tb loop
            clock_tb <= not clock_tb; -- Toggle the clock
            wait for CLOCK_PERIOD / 2; -- Half clock period
        end loop;
        wait;
    end process;

    -- Stimulus process (generate test vectors)
    process
    begin
        wait for 50 ns; -- Wait for some time to allow DUT initialization

        -- Generate a sequence of clock edges
        for i in 1 to 10 loop
            wait until rising_edge(clock_tb);
        end loop;

        -- Stop simulation
        stop_tb <= TRUE;
        wait;
    end process;

    -- Assertion process (check DUT behavior)
    process
    begin
        wait for 60 ns; -- Wait for some time to allow DUT initialization

        -- Check if the switch signal toggles as expected
        for i in 1 to 5 loop
            wait until rising_edge(clock_tb);
            assert switch_tb = '1' report "Error: Switch not toggling correctly" severity FAILURE;
            wait until rising_edge(clock_tb);
            assert switch_tb = '0' report "Error: Switch not toggling correctly" severity FAILURE;
        end loop;

        -- Stop simulation
        stop_tb <= TRUE;
        wait;
    end process;

end testbench;
