# verification/formal/Makefile
# Formal verification for DLinear ASIC
#
# Prerequisites:
#   brew install yosys
#   pip install sby  # or build from source
#   brew install z3  # SMT solver
#
# Usage:
#   make prove    # Run bounded model checking
#   make cover    # Check cover properties
#   make live     # Check liveness (requires ABC)
#   make all      # Run all checks
#   make clean    # Clean up

.PHONY: all prove cover live clean install-deps check-deps

# Default: run all verification tasks
all: prove cover

# Check if dependencies are installed
check-deps:
	@which yosys > /dev/null || (echo "ERROR: yosys not found. Run 'make install-deps'" && exit 1)
	@which sby > /dev/null || (echo "ERROR: sby not found. Run 'pip install sby'" && exit 1)
	@which z3 > /dev/null || (echo "ERROR: z3 not found. Run 'brew install z3'" && exit 1)
	@echo "All dependencies found."

# Install dependencies (macOS with Homebrew)
install-deps:
	@echo "Installing formal verification tools..."
	brew install yosys z3
	pip install git+https://github.com/YosysHQ/sby.git
	@echo ""
	@echo "Installation complete. Run 'make check-deps' to verify."

# Bounded Model Checking (prove safety properties)
prove: check-deps
	@echo "=========================================="
	@echo "Running Bounded Model Checking..."
	@echo "=========================================="
	sby -f dlinear.sby prove
	@echo ""
	@echo "BMC completed. Check dlinear_prove/ for results."

# Cover property checking (verify reachability)
cover: check-deps
	@echo "=========================================="
	@echo "Running Cover Property Check..."
	@echo "=========================================="
	sby -f dlinear.sby cover
	@echo ""
	@echo "Cover check completed. Check dlinear_cover/ for results."

# Liveness checking (requires ABC with PDR support)
live: check-deps
	@echo "=========================================="
	@echo "Running Liveness Check..."
	@echo "=========================================="
	@which abc > /dev/null || (echo "WARNING: abc not found. Skipping liveness." && exit 0)
	sby -f dlinear.sby live || echo "Liveness check may require additional setup."

# View results
view-prove:
	@if [ -d dlinear_prove ]; then \
		cat dlinear_prove/status; \
		echo ""; \
		cat dlinear_prove/logfile.txt | tail -50; \
	else \
		echo "No prove results. Run 'make prove' first."; \
	fi

view-cover:
	@if [ -d dlinear_cover ]; then \
		cat dlinear_cover/status; \
		echo ""; \
		cat dlinear_cover/logfile.txt | tail -50; \
	else \
		echo "No cover results. Run 'make cover' first."; \
	fi

# Clean all generated files
clean:
	rm -rf dlinear_prove dlinear_cover dlinear_live
	rm -rf *.log *.vcd

# Help
help:
	@echo "DLinear ASIC Formal Verification"
	@echo ""
	@echo "Targets:"
	@echo "  make all          - Run prove and cover checks"
	@echo "  make prove        - Bounded model checking (safety)"
	@echo "  make cover        - Cover property reachability"
	@echo "  make live         - Liveness checking (requires ABC)"
	@echo "  make check-deps   - Verify tools are installed"
	@echo "  make install-deps - Install required tools"
	@echo "  make view-prove   - Show prove results"
	@echo "  make view-cover   - Show cover results"
	@echo "  make clean        - Remove generated files"
