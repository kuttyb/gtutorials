#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

#define IMG_INT64_C(c)	c ## LL
#define IMG_UINT64_C(c)	c ## ULL
#define AGX_EXTRACT_FIELD(value, field_name) (((value) & ~(field_name ## _CLRMSK)) >> field_name ## _SHIFT)

/* Mock Chip data structures */
static uint32_t * fRegisters = NULL;

typedef struct {
  uint32_t num_clusters;
  uint32_t usc_indirect;
} ChipDispatch;

ChipDispatch agx_chip_data;

// G4 version
#if 1
#define RGX_CR_USC_DM_SLOT0                               (0x4178U)
#define RGX_CR_USC_DM_SLOT0_MASKFULL                      (IMG_UINT64_C(0xFFFFFFFFFFFFFFFF))
#define RGX_CR_USC_DM_SLOT0_SLOT_0_SHIFT                  (0U)
#define RGX_CR_USC_DM_SLOT0_SLOT_0_CLRMSK                 (IMG_UINT64_C(0XFFFFFFFFFFFFFFF0))
#define RGX_CR_USC_DM_SLOT0_SLOT_0_VERTEX                 (IMG_UINT64_C(0000000000000000))
#define RGX_CR_USC_DM_SLOT0_SLOT_0_PIXEL                  (IMG_UINT64_C(0x0000000000000001))
#define RGX_CR_USC_DM_SLOT0_SLOT_0_COMPUTE                (IMG_UINT64_C(0x0000000000000002))
#define RGX_CR_USC_DM_SLOT0_SLOT_0_EMPTY                  (IMG_UINT64_C(0x000000000000000f))

#define RGX_CR_USC_DM_SLOT1                               (0x4180U)
#define RGX_CR_USC_DM_SLOT1_MASKFULL                      (IMG_UINT64_C(0xFFFFFFFFFFFFFFFF))

#define RGX_CR_USC_INDIRECT                               (0x8000U)

static inline void agfWriteReg32(uint32_t * registers, uint32_t byte_offset, uint32_t value)
{
  printf("kbb: writereg32: addr 0x%x value %d\n", byte_offset, value);
}

static inline uint64_t agfReadReg64(uint32_t * registers, uint32_t byte_offset)
{
  printf("kbb: readreg64: addr 0x%x\n", byte_offset);
  if (byte_offset == 0x4178)
    {
      //      return 0xffffffffffffffffUL;     
      return 0xf1f1f1f1f1f10121UL;
    }
  else
    {
      // return 0xffffffff00000000UL;
      //      return 0xffffffffffffffffUL;
      return 0x1111111111111111;
    }
}

void AGFHALProgressCheckUSCSlots(uint32_t * signature_list, uint8_t dm)
{
	for (uint32_t indirect_idx = 0; indirect_idx < agx_chip_data.num_clusters; indirect_idx++)
	{
		uint64_t dm_slot_reg;
		uint32_t g_usc_dm[] = { RGX_CR_USC_DM_SLOT0, RGX_CR_USC_DM_SLOT1};
		
		/* Select this USC */
		agfWriteReg32(fRegisters, RGX_CR_USC_INDIRECT, indirect_idx);
		uint32_t signature = 0;
		
		/* Check all slot registers (32 slots) */
		for (uint32_t usc_slot_reg_idx = 0; usc_slot_reg_idx < 2; usc_slot_reg_idx++)
		{
			dm_slot_reg = agfReadReg64(fRegisters, g_usc_dm[usc_slot_reg_idx]);
			
			/* Iterate through the 16 slots per register */
			uint32_t shift_base = usc_slot_reg_idx * 16;
			for (uint32_t dm_slot = 0; dm_slot < 16; dm_slot++)
			{
				uint32_t	slot_data = ((dm_slot_reg >> (dm_slot * 4)) & ~RGX_CR_USC_DM_SLOT0_SLOT_0_CLRMSK);
				if (slot_data == dm)
				{
					signature |= 1 << (dm_slot + shift_base);
				}
			}
		}
		signature_list[indirect_idx] = signature;
	}
}

#else
// G5 version
#define AGX_CR_USC_SLOT0                                   (0x00011200U)
#define AGX_CR_USC_SLOT0_RST                               (0x0000000000000000ULL)
#define AGX_CR_USC_SLOT0_RSTMASK                           (0x0000000F00000001ULL) //Indicates fields which have reset values 1-has a reset value, 0-reset value is undefined
                                 
#define AGX_CR_USC_SLOT0_VALIDMASK                         (0x000000FFFFFFFFFFULL) //Indicates valid fields 0- Reserved, 1 - valid bit     
// Indicates whether this slot is valid or not. If this bit is '0' then the state field is also '0'
#define AGX_CR_USC_SLOT0_V_SHIFT                             (0U)
#define AGX_CR_USC_SLOT0_V_CLRMSK                            (0xFFFFFFFFFFFFFFFEULL)    
// The PC is valid  
#define AGX_CR_USC_SLOT0_V_VALID                             (0x0000000000000001ULL)    

// The DM for slot 0
#define AGX_CR_USC_SLOT0_DM_SHIFT                            (36U)
#define AGX_CR_USC_SLOT0_DM_CLRMSK                           (0xFFFFFF0FFFFFFFFFULL)    
// Slot 0 is executing a task from the vertex data master 
#define AGX_CR_USC_SLOT0_DM_VERTEX                           (0x000000000000000ULL)    
// Slot 0 is executing a task from the pixel data master  
#define AGX_CR_USC_SLOT0_DM_PIXEL                            (0x0000001000000000ULL)    
// Slot 0 is executing a task from the compute data master    
#define AGX_CR_USC_SLOT0_DM_COMPUTE                          (0x0000002000000000ULL)      

static inline void agfWriteReg32(uint32_t * registers, uint32_t byte_offset, uint32_t value)
{
  printf("kbb: writereg32: addr 0x%x value %d\n", byte_offset, value);
}

static inline uint64_t agfReadReg64(uint32_t * registers, uint32_t byte_offset)
{
  printf("kbb: readreg64: addr 0x%x\n", byte_offset);
  switch (byte_offset)
    {
      /* Slot 0, 3, 30 and 31 using Pixel. Slot 1 using Pixel but invalid.
       * So, signature should say 0xc0000009
       */
    case 0x11200:
      return 0x1000000001ULL;

    case 0x11208:
      return 0x1ULL;

    case 0x11218:
      return 0x1000000001ULL;

    case 0x112f0:
      return 0x1000000001ULL;

    case 0x112f8:
      return 0x1000000001ULL;

    default:
      return 0x0ULL;
    }
  return 0x0ULL;
}

void AGFHALProgressCheckUSCSlots(uint32_t * signature_list, uint8_t dm)
{
	static uint32_t const NUM_SLOTS = 32;
	
	for (uint32_t indirect_idx = 0; indirect_idx < agx_chip_data.num_clusters; indirect_idx++)
	{
		/* Select this USC */
		agfWriteReg32(fRegisters, agx_chip_data.usc_indirect, indirect_idx);
		uint32_t signature = 0;
		
		for (uint32_t slot = 0; slot < NUM_SLOTS; slot++)
		{
			uint64_t usc_slot = agfReadReg64(fRegisters, AGX_CR_USC_SLOT0 + (slot * sizeof(uint64_t)));
			
			if (AGX_EXTRACT_FIELD(usc_slot, AGX_CR_USC_SLOT0_V) == AGX_CR_USC_SLOT0_V_VALID)
			{
				uint64_t slot_dm = AGX_EXTRACT_FIELD(usc_slot, AGX_CR_USC_SLOT0_DM);
				if (slot_dm == dm)
				{
					signature |= 1 << slot;
				}
			}
		}
		signature_list[indirect_idx] = signature;
	}
}
#endif

static void printSignatures(uint32_t * signature_list)
{
  printf("=================\n");
  for (uint32_t i = 0; i < 16; ++i)
    {
      printf("kbb: signature[%d] = 0x%x\n", i, signature_list[i]);
    }
  printf("=================\n");
}

int main(void) 
{
  agx_chip_data.num_clusters = 8;
  agx_chip_data.usc_indirect = 0xffee;
  uint32_t signatures[32] = { 0 };

  printSignatures(signatures);
#if 1
  AGFHALProgressCheckUSCSlots(signatures, 1);
#else
  AGFHALProgressCheckUSCSlots(signatures, 1);
#endif
  printSignatures(signatures);

  return 0;
}
