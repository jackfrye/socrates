module spram #(
  parameter integer DEPTH = 1024,
  parameter integer WIDTH = 32
) 
(
  input                            clk ,
  input                            rst ,
  input                            wr  ,
  input                            en  ,
  input        [WIDTH-1:0]         dwr ,
  input        [$clog2(DEPTH)-1:0] addr,
  output logic [WIDTH-1:0]         drd
);

  logic [WIDTH-1:0] mem [DEPTH-1:0];
  
  always @(posedge clk)
  begin
    if(en)
    begin
      if(wr)
      begin
        mem[addr] <= dwr;
      end
      else
      begin
        drd <= mem[addr];
      end
    end
  end

endmodule 
