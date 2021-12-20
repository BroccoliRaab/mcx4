/*
BSD 2-Clause License

Copyright (c) 2021, Robert Herlihy
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define MCX4_DRIVER_VERSION "v0.1.0"

const struct pci_matchid mcx4_devices[] = {
	{ PCI_VENDOR_MELLANOX, PCI_PRODUCT_MELLANOX_MT27500 }
};

struct cfattach mcx4_ca = {
	sizeof(struct mcx4_softc), mcx4_probe, mcx4_attach
};

struct cfdriver mcx4_cd = {
	NULL, "mcx4", DV_IFNET
};

int    mcx4_probe( struct device *, void *, void *);
void   mcx4_attach(struct device *, struct device *, void *);

int
mcx4_probe(struct device *parent, void *match, void *aux)
{
	return pci_matchbyid((struct pci_attach_args *)aux, mcx4_device
		nitems(mcx4_devices));
}

void
mcx4_attach(struct device *parent, struct device *self, void *aux)
{
	struct pci_attach_args *pa = aux;
	struct mcx4_softc *sc = (struct mcx_softc *) self;
}
