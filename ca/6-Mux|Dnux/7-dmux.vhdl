LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY dmux1to4 IS
END dmux1to4;

ARCHITECTURE behavior OF dmux1to4 IS
    SIGNAL D   : STD_LOGIC := '0';
    SIGNAL Sel : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00";
    SIGNAL Y0, Y1, Y2, Y3 : STD_LOGIC;
BEGIN
    PROCESS(D, Sel)
    BEGIN
        -- Initialize outputs to 0
        Y0 <= '0';
        Y1 <= '0';
        Y2 <= '0';
        Y3 <= '0';

        -- Assign D to the correct output based on Sel
        CASE Sel IS
            WHEN "00" => Y0 <= D;
            WHEN "01" => Y1 <= D;
            WHEN "10" => Y2 <= D;
            WHEN "11" => Y3 <= D;
            WHEN OTHERS => NULL;
        END CASE;
    END PROCESS;

    -- Generate Test Inputs Inside the Same File
    STIMULUS: PROCESS
    BEGIN
        -- Test Case 1
        D <= '1'; Sel <= "00"; WAIT FOR 10 ns;
        -- Test Case 2
        Sel <= "01"; WAIT FOR 10 ns;
        -- Test Case 3
        Sel <= "10"; WAIT FOR 10 ns;
        -- Test Case 4
        Sel <= "11"; WAIT FOR 10 ns;
        -- End Simulation
        WAIT;
    END PROCESS;
END behavior;

