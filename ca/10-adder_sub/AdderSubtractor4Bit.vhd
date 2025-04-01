library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Testbench is
end Testbench;

architecture Behavior of Testbench is
  signal A      : STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
  signal B      : STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
  signal AddSub : STD_LOGIC := '0';
  
  signal Result : STD_LOGIC_VECTOR(3 downto 0);
  signal Cout   : STD_LOGIC;
  
  signal B_mod  : STD_LOGIC_VECTOR(3 downto 0);
  signal Cin    : STD_LOGIC;
  signal Sum    : STD_LOGIC_VECTOR(4 downto 0);
  
begin
  B_mod <= not B when AddSub = '1' else B;
  Cin   <= AddSub;
  
  Sum <= std_logic_vector(resize(unsigned(A), 5) + resize(unsigned(B_mod), 5) + 
         ("0000" & Cin));
  
  Result <= Sum(3 downto 0);
  Cout   <= Sum(4);
  
  stimulus: process
  begin
    -- Test Addition (AddSub = '0')
    A <= "0100"; B <= "0011"; AddSub <= '0'; wait for 10 ns; -- 4 + 3 = 7
    A <= "1000"; B <= "0111"; AddSub <= '0'; wait for 10 ns; -- 8 + 7 = 15
    A <= "1111"; B <= "0001"; AddSub <= '0'; wait for 10 ns; -- 15 + 1 = 0 (Cout='1')
    
    -- Test Subtraction (AddSub = '1')
    A <= "0011"; B <= "0100"; AddSub <= '1'; wait for 10 ns; -- 3 - 4 = -1 (1111)
    A <= "0100"; B <= "0011"; AddSub <= '1'; wait for 10 ns; -- 4 - 3 = 1 (0001)
    A <= "0000"; B <= "0001"; AddSub <= '1'; wait for 10 ns; -- 0 - 1 = -1 (1111)
    
    report "Simulation complete" severity note;
    wait;
  end process;
  
  monitor: process
    variable result_int : integer;  -- Temporary variable to store the result
  begin
    wait on A, B, AddSub;
    if now > 0 ns then
      wait for 1 ns;
      
      -- Determine if we should interpret Result as signed or unsigned
      if AddSub = '1' then
        result_int := to_integer(signed(Result));  -- Subtraction: signed
      else
        result_int := to_integer(unsigned(Result)); -- Addition: unsigned
      end if;
      
      report "Time: " & time'image(now) & 
             ", A = " & integer'image(to_integer(unsigned(A))) &
             ", B = " & integer'image(to_integer(unsigned(B))) &
             ", AddSub = " & std_logic'image(AddSub) &
             ", Result = " & integer'image(result_int) &
             ", Cout = " & std_logic'image(Cout);
    end if;
  end process;
  
end Behavior;
