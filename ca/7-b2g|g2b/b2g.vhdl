library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bin2gray is
end entity;

architecture behaviour of bin2gray is
  signal n : std_logic_vector(3 downto 0);
  signal gray_n : std_logic_vector(3 downto 0);
begin
  process
  begin
    -- Assign input binary number
    n <= "1010";
    wait for 10 ns;
  end process;

  process(n)  -- Instead of "process(n)", use "process(all)" to react to any change.
  begin
    gray_n(3) <= n(3);
    gray_n(2) <= n(3) xor n(2);
    gray_n(1) <= n(2) xor n(1);
    gray_n(0) <= n(1) xor n(0);
  end process;
end behaviour;

