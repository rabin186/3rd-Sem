library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity aluTB is
end aluTB;

architecture Behavior of aluTB is
  signal A         : STD_LOGIC_VECTOR(3 downto 0) := "0000";
  signal B         : STD_LOGIC_VECTOR(3 downto 0) := "0000";
  signal ALU_Sel   : STD_LOGIC_VECTOR(2 downto 0) := "000";
  signal ALU_Out   : STD_LOGIC_VECTOR(3 downto 0);
  signal Carry_Out : STD_LOGIC;
  signal stop_sim  : BOOLEAN := FALSE;
  
begin
  -- ALU process
  alu_process: process(A, B, ALU_Sel)
    variable temp : STD_LOGIC_VECTOR(4 downto 0);
  begin
    case ALU_Sel is
      when "000" => temp := std_logic_vector(resize(unsigned(A), 5) + resize(unsigned(B), 5));
      when "001" => temp := std_logic_vector(resize(unsigned(A), 5) - resize(unsigned(B), 5));
      when "010" => temp := '0' & (A and B);
      when "011" => temp := '0' & (A or B);
      when "100" => temp := '0' & (A xor B);
      when "101" => temp := '0' & (not A);
      when "110" => temp := '0' & B;
      when "111" => temp := '0' & A;
      when others => temp := (others => '0');
    end case;
    
    Carry_Out <= temp(4);
    ALU_Out <= temp(3 downto 0);
  end process;
  
  -- Test process
  stimulus: process
  begin
    -- Initial values
    A <= "1010"; B <= "0011"; ALU_Sel <= "000";
    wait for 10 ns;
    
    -- Test cases
    ALU_Sel <= "001"; wait for 10 ns;  -- Subtraction (10 - 3)
    ALU_Sel <= "010"; wait for 10 ns;  -- AND
    ALU_Sel <= "011"; wait for 10 ns;  -- OR
    ALU_Sel <= "100"; wait for 10 ns;  -- XOR
    ALU_Sel <= "101"; wait for 10 ns;  -- NOT A
    ALU_Sel <= "110"; wait for 10 ns;  -- Return B
    ALU_Sel <= "111"; wait for 10 ns;  -- Return A
    
    -- Overflow test
    A <= "1111"; B <= "0011"; ALU_Sel <= "000"; wait for 10 ns;
    
    stop_sim <= TRUE;
    report "Simulation complete" severity note;
    wait;
  end process;
  
  -- Monitor process that captures all operations
  monitor: process
  begin
    -- Report initial state
    wait for 1 ns;
    report "Time: " & time'image(now) & 
           ", A = " & integer'image(to_integer(unsigned(A))) &
           ", B = " & integer'image(to_integer(unsigned(B))) &
           ", ALU_Sel = " & integer'image(to_integer(unsigned(ALU_Sel))) &
           ", ALU_Out = " & integer'image(to_integer(unsigned(ALU_Out))) &
           ", Carry_Out = " & std_logic'image(Carry_Out);
    
    -- Report after each operation change
    for i in 1 to 8 loop
      wait until ALU_Sel'event or A'event or B'event;
      wait for 1 ns;
      report "Time: " & time'image(now) & 
             ", A = " & integer'image(to_integer(unsigned(A))) &
             ", B = " & integer'image(to_integer(unsigned(B))) &
             ", ALU_Sel = " & integer'image(to_integer(unsigned(ALU_Sel))) &
             ", ALU_Out = " & integer'image(to_integer(unsigned(ALU_Out))) &
             ", Carry_Out = " & std_logic'image(Carry_Out);
    end loop;
    
    wait;
  end process;
  
end Behavior;
