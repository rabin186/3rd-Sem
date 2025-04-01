library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity gray2bin is
end entity;

architecture behaviour of gray2bin is
  signal gray_n : std_logic_vector(3 downto 0);
  signal n : std_logic_vector(3 downto 0);
begin
  -- Stimulus Process
  process
  begin
    gray_n <= "1111";  -- Set input Gray code
    wait for 10 ns;
    report "Binary Output: " & std_logic'image(n(3)) & std_logic'image(n(2)) &
                              std_logic'image(n(1)) & std_logic'image(n(0));
    wait;
  end process;

  -- Convert Gray to Binary using a temporary variable
  process(gray_n)
    variable temp : std_logic_vector(3 downto 0);
  begin
    temp(3) := gray_n(3);
    temp(2) := temp(3) xor gray_n(2);
    temp(1) := temp(2) xor gray_n(1);
    temp(0) := temp(1) xor gray_n(0);
    n <= temp;  -- Assign to output signal
  end process;
end behaviour;

