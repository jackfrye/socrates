module #(
  parameter integer DEPTH = 1024,
  parameter integer WIDTH = 32
) spram
(
  input                      clk ,
  input                      rst ,
  input                      wr  ,
  input                      en  ,
  input  [WIDTH-1:0]         dwr ,
  input  [$clog2(DEPTH)-1:0] addr,
  output [WIDTH-1:0]         drd
);

  logic [DEPTH-1:0][WIDTH-1:0] mem;
  
  always_comb
  begin
    if(en & ~wr)
    begin
      drd <= mem[addr];
    end
  end
  
  always @(posedge clk)
  begin
    if(rst)
    begin
      mem <= '0;
    end
    if(en & wr)
    begin
      mem[addr] <= dwr;
    end
  end

endmodule 
