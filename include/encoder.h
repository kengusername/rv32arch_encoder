#pragma once

#include <array>
#include <tuple>
#include <variant>
#include <cstddef>
using std::tuple;
using std::variant;
using std::visit;
#define FWD(x) std::forward<decltype(x)>(x)

struct Slti {
  unsigned rd : 5, rs1 : 5;
  signed imm : 12;
};
struct Auipc {
  signed imm : 20;
  unsigned rd : 5;
};
struct Bltu {
  unsigned rs1 : 5, rs2 : 5;
  signed imm : 13;
};
struct Bgeu {
  unsigned rs1 : 5, rs2 : 5;
  signed imm : 13;
};
struct Jalr {
  unsigned rd : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};
struct Sltiu {
  unsigned rd : 5, rs1 : 5;
  signed imm : 12;
};
struct Sltu {
  unsigned rd : 5, rs2 : 5, rs1 : 5;
};
struct Addi {
  unsigned rd : 5, rs1 : 5;
  signed imm : 12;
};
struct Xor {
  unsigned rd : 5, rs2 : 5, rs1 : 5;
};
struct Lb {
  unsigned rd : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};
struct Ebreak {};
struct Slli {
  unsigned rd : 5, rs1 : 5;
  signed imm : 12;
};
struct Srli {
  unsigned rd : 5, rs1 : 5;
  signed imm : 12;
};
struct Slt {
  unsigned rd : 5, rs1 : 5, rs2 : 5;
};
struct Fence {
  unsigned fm : 4, pred : 4, succ : 4, rs1 : 5, rd : 5;
};
struct Beq {
  unsigned rs1 : 5, rs2 : 5;
  signed imm : 13;
};
struct Lui {
  unsigned rd : 5;
  signed imm : 20;
};
struct Sh {
  unsigned rs2 : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};
struct Or {
  unsigned rd : 5, rs2 : 5, rs1 : 5;
};
struct Xori {
  unsigned rd : 5, rs1 : 5;
  signed imm : 12;
};
struct Sw {
  unsigned rs2 : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};
struct Lhu {
  unsigned rd : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};
struct Srai {
  unsigned rd : 5, rs1 : 5, shamt : 5;
};
struct And {
  unsigned rd : 5, rs2 : 5, rs1 : 5;
};
struct Ori {
  unsigned rd : 5, rs1 : 5;
  signed imm : 12;
};
struct Sb {
  unsigned rs2 : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};
struct Jal {
  unsigned rd : 5;
  signed imm : 20;
};
struct Andi {
  unsigned rd : 5, rs1 : 5;
  signed imm : 12;
};
struct Ecall {};
struct Bne {
  unsigned rs1 : 5, rs2 : 5;
  signed imm : 13;
};
struct Lh {
  unsigned rd : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};
struct Lw {
  unsigned rd : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};
struct Sub {
  unsigned rd : 5, rs1, rs2;
};
struct Add {
  unsigned rd : 5, rs1, rs2;
};
struct Sll {
  unsigned rd : 5, rs1, rs2;
};
struct Srl {
  unsigned rd : 5, rs1, rs2;
};
struct Sra {
  unsigned rd : 5, rs1, rs2;
};
struct Bge {
  unsigned rs1 : 5, rs2 : 5;
  signed imm : 13;
};
struct Blt {
  unsigned rs1 : 5, rs2 : 5;
  signed imm : 13;
};
struct Lbu {
  unsigned rd : 5;
  signed imm : 12;
  unsigned rs1 : 5;
};

using op_variant =
    variant<Slti, Auipc,Bltu, Bgeu, Jalr, Sltiu, Sltu, Addi, Xor, Lb,
            Ebreak, Slli, Srli, Slt, Fence, Beq, Lui, Sh, Or, Xori, Sw, Lhu,
            Srai, And, Ori, Sb, Jal, Andi, Ecall, Bne, Lh, Lw, Sub, Add, Sll,
            Srl, Sra, Bge, Blt, Lbu>;

template <typename... xs> struct overload : xs... {
  using xs::operator()...;
};

namespace details {
constexpr auto ADD = tuple{0b0000000, 0b000, 0b0110011};
constexpr auto ADDI = tuple{0b000, 0b0010011};
constexpr auto AND = tuple{0b0000000, 0b111, 0b0110011};
constexpr auto ANDI = tuple{0b111, 0b0010011};
constexpr auto AUIPC = tuple{0b0010111};
constexpr auto BEQ = tuple{0b000, 0b1100011};
constexpr auto BGE = tuple{0b101, 0b1100011};
constexpr auto BGEU = tuple{0b111, 0b1100011};
constexpr auto BLT = tuple{0b100, 0b1100011};
constexpr auto BLTU = tuple{0b110, 0b1100011};
constexpr auto BNE = tuple{0b001, 0b1100011};
constexpr auto EBREAK = tuple{0b00000000000100000000000001110011};
constexpr auto ECALL = tuple{0b00000000000000000000000001110011};
constexpr auto FENCE = tuple{0b000, 0b0001111};
constexpr auto JAL = tuple{0b1101111};
constexpr auto JALR = tuple{0b000, 0b1100111};
constexpr auto LB = tuple{0b000, 0b0000011};
constexpr auto LBU = tuple{0b100, 0b0000011};
constexpr auto LH = tuple{0b001, 0b0000011};
constexpr auto LHU = tuple{0b101, 0b0000011};
constexpr auto LUI = tuple{0b0110111};
constexpr auto LW = tuple{0b010, 0b0000011};
constexpr auto OR = tuple{0b0000000, 0b110, 0b0110011};
constexpr auto ORI = tuple{0b110, 0b0010011};
constexpr auto SB = tuple{0b000, 0b0100011};
constexpr auto SH = tuple{0b001, 0b0100011};
constexpr auto SLL = tuple{0b0000000, 0b001, 0b0110011};
constexpr auto SLLI = tuple{0b0000000, 0b001, 0b0010011};
constexpr auto SLT = tuple{0b0000000, 0b010, 0b0110011};
constexpr auto SLTI = tuple{0b010, 0b0010011};
constexpr auto SLTIU = tuple{0b011, 0b0010011};
constexpr auto SLTU = tuple{0b0000000, 0b011, 0b0110011};
constexpr auto SRA = tuple{0b0100000, 0b101, 0b0110011};
constexpr auto SRAI = tuple{0b0100000, 0b101, 0b0010011};
constexpr auto SRL = tuple{0b0000000, 0b101, 0b0110011};
constexpr auto SRLI = tuple{0b0000000, 0b101, 0b0010011};
constexpr auto SUB = tuple{0b0100000, 0b000, 0b0110011};
constexpr auto SW = tuple{0b010, 0b0100011};
constexpr auto XOR = tuple{0b0000000, 0b100, 0b0110011};
constexpr auto XORI = tuple{0b100, 0b0010011};
};

constexpr auto ref_tuple(auto &&...xs) {
  return tuple<decltype(xs)...>{FWD(xs)...};
}

constexpr auto shift_and_or(auto &&arg1, auto &&arg2) {
  auto &&[... shift] = arg1;
  auto &&[... val] = arg2;
  unsigned ret{};
  ret |= ((val << shift) | ...);
  return ret;
}
constexpr auto operator""_iorw(const char *s, size_t size) {
  signed ret{};
  constexpr auto table = []() {
    std::array<char, 127> x{};
    x[105] = 8;
    x[111] = 4;
    x[114] = 2;
    x[119] = 1;
    return x;
  }();
  for (auto i = 0; i < size; ++i) {
    ret |= table[s[i]];
  }
  return ret;
}

constexpr auto encode = overload{
    []<auto = 0>(const Auipc &x) {
      constexpr auto &pred = details::AUIPC;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{0}, tuple{7, 12}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Bltu &x) {
      constexpr auto &pred = details::BLTU;

      auto msb = (x.imm & 1 << 12) >> 12;
      auto imm_11 = (x.imm & 1 << 11) >> 11;
      auto imm_10_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_1 = (x.imm & 0x1E) >> 1;
      signed rs2 = x.rs2, rs1 = x.rs1;
      static constexpr auto [p, n] =
          tuple{tuple{12, 0}, tuple{31, 25, 20, 15, 7, 8}};

      auto fields = ref_tuple(msb, imm_10_5, rs2, rs1, imm_11, imm_4_1);
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Bgeu &x) {
      constexpr auto &pred = details::BGEU;

      auto msb = (x.imm & 1 << 12) >> 12;
      auto imm_11 = (x.imm & 1 << 11) >> 11;
      auto imm_10_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_1 = (x.imm & 0x1E) >> 1;
      signed rs2 = x.rs2, rs1 = x.rs1;
      static constexpr auto [p, n] =
          tuple{tuple{12, 0}, tuple{31, 25, 20, 15, 7, 8}};

      auto fields = ref_tuple(msb, imm_10_5, rs2, rs1, imm_11, imm_4_1);
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Jalr &x) {
      constexpr auto &pred = details::JALR;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 20, 15}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Sltiu &x) {
      constexpr auto &pred = details::SLTIU;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Slti &x) {
      constexpr auto &pred = details::SLTI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Sltu &x) {
      constexpr auto &pred = details::SLTU;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Addi &x) {
      constexpr auto &pred = details::ADDI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Xor &x) {
      constexpr auto &pred = details::XOR;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Lb &x) {
      constexpr auto &pred = details::LB;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 20, 15}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Ebreak &x) {
      constexpr auto &pred = details::EBREAK;
      unsigned ret = shift_and_or(tuple{0}, pred);
      return ret;
    },
    []<auto = 0>(const Slli &x) {
      constexpr auto &pred = details::SLLI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Srli &x) {
      constexpr auto &pred = details::SRLI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Slt &x) {
      constexpr auto &pred = details::SLT;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Fence &x) {
      constexpr auto &pred = details::FENCE;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] =
          tuple{tuple{12, 0}, tuple{28, 24, 20, 15, 7}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Beq &x) {
      constexpr auto &pred = details::BEQ;

      auto msb = (x.imm & 1 << 12) >> 12;
      auto imm_11 = (x.imm & 1 << 11) >> 11;
      auto imm_10_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_1 = (x.imm & 0x1E) >> 1;
      signed rs2 = x.rs2, rs1 = x.rs1;
      static constexpr auto [p, n] =
          tuple{tuple{12, 0}, tuple{31, 25, 20, 15, 7, 8}};
      auto fields = ref_tuple(msb, imm_10_5, rs2, rs1, imm_11, imm_4_1);
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Lui &x) {
      constexpr auto &pred = details::LUI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{0}, tuple{7, 12}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Sh &x) {
      constexpr auto &pred = details::SH;

      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{25, 20, 15, 7}};

      auto imm_11_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_0 = (x.imm & 0x1F);
      signed rs2 = x.rs2, rs1 = x.rs1;
      unsigned ret =
          shift_and_or(p, pred) +
          shift_and_or(n, ref_tuple(imm_11_5, rs2, rs1, imm_4_0));
      return ret;
    },
    []<auto = 0>(const Or &x) {
      constexpr auto &pred = details::OR;

      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Xori &x) {
      constexpr auto &pred = details::XORI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Sw &x) {
      constexpr auto &pred = details::SW;
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{25, 20, 15, 7}};

      auto imm_11_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_0 = (x.imm & 0x1F);
      signed rs2 = x.rs2, rs1 = x.rs1;
      unsigned ret =
          shift_and_or(p, pred) +
          shift_and_or(n, ref_tuple(imm_11_5, rs2, rs1, imm_4_0));
      return ret;
    },
    []<auto = 0>(const Lhu &x) {
      constexpr auto &pred = details::LHU;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 20, 15}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Srai &x) {
      constexpr auto &pred = details::SRAI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const And &x) {
      constexpr auto &pred = details::AND;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Ori &x) {
      constexpr auto &pred = details::ORI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Sb &x) {
      constexpr auto &pred = details::SB;
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{25, 20, 15, 7}};

      auto imm_11_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_0 = (x.imm & 0x1F);
      signed rs2 = x.rs2, rs1 = x.rs1;
      unsigned ret =
          shift_and_or(p, pred) +
          shift_and_or(n, ref_tuple(imm_11_5, rs2, rs1, imm_4_0));
      return ret;
    },
    []<auto = 0>(const Jal &x) {
      constexpr auto &pred = details::JAL;
      static constexpr auto [p, n] = tuple{tuple{0}, tuple{31, 21, 20, 12, 7}};
      auto imm_20 = (x.imm & 1 << 20) >> 20;
      auto imm_10_1 = (x.imm & 0x7FE) >> 1;
      auto imm_11 = (x.imm & 0x800) >> 11;
      auto imm_19_12 = (x.imm & 0xFF000) >> 12;
      signed rd = x.rd;
      unsigned ret = shift_and_or(p, pred) +
                     shift_and_or(n, ref_tuple(imm_20, imm_10_1, imm_11,
                                             imm_19_12, rd));
      return ret;
    },
    []<auto = 0>(const Andi &x) {
      constexpr auto &pred = details::ANDI;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Ecall &x) {
      constexpr auto &pred = details::ECALL;
      unsigned ret = shift_and_or(tuple{0}, pred);
      return ret;
    },
    []<auto = 0>(const Bne &x) {
      constexpr auto &pred = details::BNE;

      auto msb = (x.imm & 1 << 12) >> 12;
      auto imm_11 = (x.imm & 1 << 11) >> 11;
      auto imm_10_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_1 = (x.imm & 0x1E) >> 1;
      signed rs2 = x.rs2, rs1 = x.rs1;
      static constexpr auto [p, n] =
          tuple{tuple{12, 0}, tuple{31, 25, 20, 15, 7, 8}};

      auto fields = ref_tuple(msb, imm_10_5, rs2, rs1, imm_11, imm_4_1);
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Lh &x) {
      constexpr auto &pred = details::LH;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 20, 15}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Lw &x) {
      constexpr auto &pred = details::LW;
      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 20, 15}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Sub &x) {
      constexpr auto &pred = details::SUB;

      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Add &x) {
      constexpr auto &pred = details::ADD;

      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Sll &x) {
      constexpr auto &pred = details::SLL;

      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Srl &x) {
      constexpr auto &pred = details::SRL;

      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Sra &x) {
      constexpr auto &pred = details::SRA;

      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{25, 12, 0}, tuple{7, 15, 20}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Bge &x) {
      constexpr auto &pred = details::BGE;

      auto msb = (x.imm & 1 << 12) >> 12;
      auto imm_11 = (x.imm & 1 << 11) >> 11;
      auto imm_10_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_1 = (x.imm & 0x1E) >> 1;
      signed rs2 = x.rs2, rs1 = x.rs1;
      static constexpr auto [p, n] =
          tuple{tuple{12, 0}, tuple{31, 25, 20, 15, 7, 8}};

      auto fields = ref_tuple(msb, imm_10_5, rs2, rs1, imm_11, imm_4_1);
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Blt &x) {
      constexpr auto &pred = details::BLT;
      auto msb = (x.imm & 1 << 12) >> 12;
      auto imm_11 = (x.imm & 1 << 11) >> 11;
      auto imm_10_5 = (x.imm & 0x7E0) >> 5;
      auto imm_4_1 = (x.imm & 0x1E) >> 1;
      signed rs2 = x.rs2, rs1 = x.rs1;
      static constexpr auto [p, n] =
          tuple{tuple{12, 0}, tuple{31, 25, 20, 15, 7, 8}};

      auto fields = ref_tuple(msb, imm_10_5, rs2, rs1, imm_11, imm_4_1);
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    []<auto = 0>(const Lbu &x) {
      constexpr auto &pred = details::LBU;

      auto &[... tmp] = x;
      auto fields = tuple{ tmp...};
      static constexpr auto [p, n] = tuple{tuple{12, 0}, tuple{7, 20, 15}};
      unsigned ret = shift_and_or(p, pred) + shift_and_or(n, fields);
      return ret;
    },
    [](auto &) { return 1u; },
};

consteval void test() {
  constexpr auto lui = op_variant{Lui{2, 4}};
  constexpr auto auipc = op_variant{Auipc{2, 4}};
  constexpr auto jal = op_variant{Jal{2, 4}};
  constexpr auto jalr = op_variant{Jalr{2, 4, 6}};
  constexpr auto beq = op_variant{Beq{2, 4, 6}};
  constexpr auto bne = op_variant{Bne{2, 6, 7}};
  constexpr auto blt = op_variant{Blt{2, 6, 8}};
  constexpr auto bge = op_variant{Bge{2, 6, 8}};
  constexpr auto bltu = op_variant{Bltu{2, 4, 4094}};
  constexpr auto bgeu = op_variant{Bgeu{2, 4, 68}};
  constexpr auto lb = op_variant{Lb{2, 67, 4}};
  constexpr auto lh = op_variant{Lh{2, 67, 4}};
  constexpr auto lw = op_variant{Lw{2, 67, 4}};
  constexpr auto lbu = op_variant{Lbu{2, 67, 4}};
  constexpr auto lhu = op_variant{Lhu{2, 67, 4}};
  constexpr auto sb = op_variant{Sb{2, 87, 4}};
  constexpr auto sh = op_variant{Sh{2, 87, 4}};
  constexpr auto sw = op_variant{Sw{2, 87, 4}};
  constexpr auto addi = op_variant{Addi{2, 4, 127}};
  constexpr auto slti = op_variant{Slti{2, 4, 127}};
  constexpr auto sltiu = op_variant{Sltiu{2, 4, 127}};
  constexpr auto xori = op_variant{Xori{2, 4, 55}};
  constexpr auto ori = op_variant{Ori{2, 4, 55}};
  constexpr auto andi = op_variant{Andi{2, 4, 55}};
  constexpr auto slli = op_variant{Slli{2, 4, 27}};
  constexpr auto srli = op_variant{Srli{2, 4, 27}};
  constexpr auto srai = op_variant{Srai{2, 4, 27}};
  constexpr auto add = op_variant{Add{2, 4, 5}};
  constexpr auto sub = op_variant{Sub{2, 4, 5}};
  constexpr auto sll = op_variant{Sll{2, 4, 5}};
  constexpr auto slt = op_variant{Slt{2, 4, 5}};
  constexpr auto sltu = op_variant{Sltu{2, 4, 5}};
  constexpr auto _xor = op_variant{Xor{2, 4, 5}};
  constexpr auto srl = op_variant{Srl{2, 4, 5}};
  constexpr auto sra = op_variant{Sra{2, 4, 5}};
  constexpr auto _or = op_variant{Or{2, 4, 5}};
  constexpr auto _and = op_variant{And{2, 4, 5}};
  constexpr auto fence = op_variant{Fence{{}, "io"_iorw, "iorw"_iorw}};
  constexpr auto ecall = op_variant{Ecall{}};
  constexpr auto ebreak = op_variant{Ebreak{}};
  static_assert(visit(encode, lui) == 16695);
  static_assert(visit(encode, auipc) == 16663);
  static_assert(visit(encode, jal) == 4194671);
  static_assert(visit(encode, jalr) == 4391271);
  static_assert(visit(encode, beq) == 4260707);
  static_assert(visit(encode, bne) == 6361955);
  static_assert(visit(encode, blt) == 6374499);
  static_assert(visit(encode, bge) == 6378595);
  static_assert(visit(encode, bltu) == 2118217699);
  static_assert(visit(encode, bgeu) == 71397987);
  static_assert(visit(encode, lb) == 70385923);
  static_assert(visit(encode, lh) == 70390019);
  static_assert(visit(encode, lw) == 70394115);
  static_assert(visit(encode, lbu) == 70402307);
  static_assert(visit(encode, lhu) == 70406403);
  static_assert(visit(encode, sb) == 69340067);
  static_assert(visit(encode, sh) == 69344163);
  static_assert(visit(encode, sw) == 69348259);
  static_assert(visit(encode, addi) == 133300499);
  static_assert(visit(encode, slti) == 133308691);
  static_assert(visit(encode, sltiu) == 133312787);
  static_assert(visit(encode, xori) == 57819411);
  static_assert(visit(encode, ori) == 57827603);
  static_assert(visit(encode, andi) == 57831699);
  static_assert(visit(encode, slli) == 28446995);
  static_assert(visit(encode, srli) == 28463379);
  static_assert(visit(encode, srai) == 1102205203);
  static_assert(visit(encode, add) == 5374259);
  static_assert(visit(encode, sub) == 1079116083);
  static_assert(visit(encode, sll) == 5378355);
  static_assert(visit(encode, slt) == 5382451);
  static_assert(visit(encode, sltu) == 5386547);
  static_assert(visit(encode, _xor) == 5390643);
  static_assert(visit(encode, srl) == 5394739);
  static_assert(visit(encode, sra) == 1079136563);
  static_assert(visit(encode, _or) == 5398835);
  static_assert(visit(encode, _and) == 5402931);
  static_assert(visit(encode, fence) == 217055247);
  static_assert(visit(encode, ecall) == 115);
  static_assert(visit(encode, ebreak) == 1048691);
}
static_assert((test(), 1));
