From [Madeline 2.0 PDE Docs](https://madeline.med.umich.edu/madeline/documentation.php) and [Madeline 2.0 PDE Source](https://github.com/piratical/Madeline_2.0_PDE).

Columns
=======
Core fields
-----------
- FamilyId
- IndividualId
- Gender
- Father
- Mother

IndiviualId type
----------------
First character of the IndividualId:

- `^` No offspring
- `&` No offspring (infertility)
- `@` Terminated pregnancy
- `!` Virtual (inserted by Madeline)

Optional "Core" fields
----------------------
- Affected
- Sampled
- DZTwin
- MZTwin
- DOB
- Proband
- Deceased
- Consultand
- Carrier

Optional "Affected" fields
--------------------------
- Affected_`*`

Optional fields
---------------
- `*`

Column types
------------
- `S` STRING
- `N` NUMBER
- `X` GENDER
- `G` GENOTYPE
- `H` HAPLOTYPE
- `D` DATE in ISO "YYYY-MM-DD" format
- `A` ALLELE
- `B` BOOLEAN

