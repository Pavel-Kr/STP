#pragma once

enum TOptrn {
	None = 0,
	Add,
	Sub,
	Mul,
	Div
};

enum TFunc {
	Rev,
	Sqr
};

template <class T>
class TProc
{
	T lop_res;
	T rop;
	TOptrn operation;
public:
	TProc() {
		reset();
	}
	void reset() {
		lop_res = T();
		rop = T();
		operation = None;
	}
	void reset_operation() {
		operation = None;
	}
	void do_operation() {
		switch (operation)
		{
		case None:
			break;
		case Add:
			lop_res = lop_res + rop;
			break;
		case Sub:
			lop_res = lop_res - rop;
			break;
		case Mul:
			lop_res = lop_res * rop;
			break;
		case Div:
			lop_res = lop_res / rop;
			break;
		default:
			break;
		}
	}
	void apply_func(TFunc func) {
		switch (func)
		{
		case Rev:
			// wtf is rev???
			break;
		case Sqr:
			rop *= rop;
			break;
		default:
			break;
		}
	}
	T read_lop() {
		return lop_res;
	}
	void write_lop(T op) {
		lop_res = op;
	}
	T read_rop() {
		return rop;
	}
	void write_rop(T op) {
		rop = op;
	}
	TOptrn read_operation() {
		return operation;
	}
	void set_operation(TOptrn op) {
		operation = op;
	}
};

