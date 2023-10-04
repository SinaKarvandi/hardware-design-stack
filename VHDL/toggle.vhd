library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Switch_Control is
    Port (
        clock   : in  STD_LOGIC;       -- clock input
        switch  : out STD_LOGIC := '0' -- Initialize switch to OFF (logic low)
    );
end Switch_Control;

architecture Behavioral of Switch_Control is
    signal toggle : STD_LOGIC := '0'; -- Signal for toggling the switch
begin
    process(clock)
    begin
        if rising_edge(clock) then
            toggle <= not toggle; -- Toggle the switch state on rising edge of the clock
        end if;
    end process;

    switch <= toggle; -- Assign the switch state to the output port
end Behavioral;
