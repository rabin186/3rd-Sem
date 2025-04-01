library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Testbench is
end Testbench;

architecture Behavior of Testbench is
  signal S      : STD_LOGIC := '0';
  signal R      : STD_LOGIC := '0';
  signal CLK    : STD_LOGIC := '0';
  signal Q      : STD_LOGIC := '0';
  signal Q_bar  : STD_LOGIC := '1';
  signal stop_sim : BOOLEAN := FALSE;
  
begin
  -- SR Flip-Flop Process
  process(CLK)
  begin
    if rising_edge(CLK) then
      if (S = '0' and R = '0') then
        null;  -- Hold state
      elsif (S = '0' and R = '1') then
        Q <= '0';
      elsif (S = '1' and R = '0') then
        Q <= '1';
      else
        Q <= 'X';  -- Invalid state
      end if;
    end if;
  end process;

  Q_bar <= not Q;

  -- Clock Generation (stops when simulation completes)
  clock_gen: process
  begin
    while not stop_sim loop
      CLK <= '0';
      wait for 5 ns;
      CLK <= '1';
      wait for 5 ns;
    end loop;
    wait;
  end process;
  
  -- Stimulus Process
  stimulus: process
  begin
    -- Initial state
    S <= '0'; R <= '0'; wait for 10 ns;
    
    -- Test cases
    S <= '0'; R <= '1'; wait for 20 ns;  -- Reset
    S <= '1'; R <= '0'; wait for 20 ns;  -- Set
    S <= '1'; R <= '1'; wait for 20 ns;  -- Invalid
    
    -- End simulation
    stop_sim <= TRUE;
    report "Simulation complete" severity note;
    wait;
  end process;
  
  -- Monitor Process (only reports on important changes)
  monitor: process(S, R, Q)
    variable last_report : TIME := 0 ns;
  begin
    -- Only report if:
    -- 1. Not at time 0
    -- 2. At least 1ns has passed since last report
    -- 3. CLK is high (to avoid reporting during transitions)
    if now > 0 ns and (now - last_report) > 1 ns and CLK = '1' then
      report "Time: " & time'image(now) & 
             " | CLK: '1'" &
             " | S: " & std_logic'image(S) &
             " | R: " & std_logic'image(R) &
             " | Q: " & std_logic'image(Q) &
             " | Q_bar: " & std_logic'image(Q_bar);
      last_report := now;
    end if;
  end process;
  
end Behavior;
