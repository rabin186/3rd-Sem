LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- 4:1 MUX
ENTITY mux4to1 IS
END mux4to1;

ARCHITECTURE behavior OF mux4to1 IS
    SIGNAL A, B, C, D : STD_LOGIC := '0';
    SIGNAL S : STD_LOGIC_VECTOR(1 DOWNTO 0) := "00"; -- 2-bit selection line
    SIGNAL Y : STD_LOGIC;
BEGIN
    PROCESS(A, B, C, D, S)
    BEGIN
        CASE S IS
            WHEN "00" => Y <= A;
            WHEN "01" => Y <= B;
            WHEN "10" => Y <= C;
            WHEN "11" => Y <= D;
            WHEN OTHERS => Y <= '0';
        END CASE;
    END PROCESS;

    -- Generate Test Inputs Inside the Same File
    STIMULUS: PROCESS
    BEGIN
      -- Initial values
      A <= '0'; B <= '1'; C <= '0'; D <= '0';

      -- Test Case 1: Select A (should be 1)
      S <= "00"; A <= '1'; WAIT FOR 10 ns;
    
      -- Test Case 2: Select B
      S <= "01"; WAIT FOR 10 ns;
    
      -- Test Case 3: Select C
      S <= "10"; WAIT FOR 10 ns;
    
      -- Test Case 4: Select D
      S <= "11"; WAIT FOR 10 ns;
    
      -- End Simulation
      WAIT;
    END PROCESS;
END behavior;

